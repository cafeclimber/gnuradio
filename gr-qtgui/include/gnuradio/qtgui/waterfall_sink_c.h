/* -*- c++ -*- */
/*
 * Copyright 2012,2014-2015 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#ifndef INCLUDED_QTGUI_WATERFALL_SINK_C_H
#define INCLUDED_QTGUI_WATERFALL_SINK_C_H

#include <gnuradio/fft/window.h>
#include <gnuradio/qtgui/api.h>
#include <gnuradio/sync_block.h>
#include <qapplication.h>

namespace gr {
namespace qtgui {

/*!
 * \brief A graphical sink to display multiple signals on a
 * waterfall (spectrogram) plot.
 * \ingroup block_qtgui_waterfall_sink
 * \ingroup block_qtgui_waterfall_sink
 *
 * \details
 * This is a QT-based graphical sink the takes set of a complex
 * streams and plots a waterfall (spectrogram) plot.
 *
 * Note that unlike the other qtgui sinks, this one does not
 * support multiple input streams. We have yet to figure out a
 * good way to display multiple, independent signals on this kind
 * of a plot. If there are any suggestions or examples of this, we
 * would love to see them. Otherwise, to display multiple signals
 * here, it's probably best to sum the signals together and
 * connect that here.
 *
 * The sink supports plotting streaming complex data or
 * messages. The message port is named "in". The two modes cannot
 * be used simultaneously, and \p nconnections should be set to 0
 * when using the message mode. GRC handles this issue by
 * providing the "Complex Message" type that removes the streaming
 * port(s).
 *
 * This sink can plot messages that contain either uniform vectors
 * of complex 32 values (pmt::is_c32vector) or PDUs where the data
 * is a uniform vector of complex 32 values.
 *
 * Message Ports:
 *
 * - freq (input):
 *        Receives a PMT pair: (intern("freq"), double(frequency)).
 *        This is used to retune the center frequency of the
 *        display's x-axis.
 *
 * - bw (input):
 *        Receives a PMT pair: (intern("bw"), double(bandwidth)).
 *        This is used to programmatically change the bandwidth of
 *        of the display's x-axis.
 *
 * - freq (output):
 *        Produces a PMT pair with (intern("freq"), double(frequency)).
 *        When a user double-clicks on the display, the block
 *        produces and emits a message containing the frequency of
 *        where on the x-axis the user clicked. This value can be
 *        used by other blocks to update their frequency setting.
 *
 *        To perform click-to-tune behavior, this output 'freq'
 *        port can be redirected to this block's input 'freq' port
 *        to catch the message and update the center frequency of
 *        the display.
 */
class QTGUI_API waterfall_sink_c : virtual public sync_block
{
public:
    // gr::qtgui::waterfall_sink_c::sptr
    typedef std::shared_ptr<waterfall_sink_c> sptr;

    /*!
     * \brief Build a complex waterfall sink.
     *
     * \param fftsize size of the FFT to compute and display. If using
     *        the PDU message port to plot samples, the length of
     *        each PDU must be a multiple of the FFT size.
     * \param wintype type of window to apply (see gr::fft::window::win_type)
     * \param fc center frequency of signal (use for x-axis labels)
     * \param bw bandwidth of signal (used to set x-axis labels)
     * \param name title for the plot
     * \param nconnections number of signals to be connected to the
     *        sink. The PDU message port is always available for a
     *        connection, and this value must be set to 0 if only
     *        the PDU message port is being used.
     * \param parent a QWidget parent object, if any
     */
    static sptr make(int fftsize,
                     int wintype,
                     double fc,
                     double bw,
                     const std::string& name,
                     int nconnections = 1,
                     QWidget* parent = NULL);

    virtual void exec_() = 0;
    virtual QWidget* qwidget() = 0;

    virtual void clear_data() = 0;

    virtual void set_fft_size(const int fftsize) = 0;
    virtual int fft_size() const = 0;
    virtual void set_time_per_fft(const double t) = 0;
    virtual void set_fft_average(const float fftavg) = 0;
    virtual float fft_average() const = 0;
    virtual void set_fft_window(const gr::fft::window::win_type win) = 0;
    virtual gr::fft::window::win_type fft_window() = 0;

    virtual void set_frequency_range(const double centerfreq, const double bandwidth) = 0;
    virtual void set_intensity_range(const double min, const double max) = 0;

    virtual void set_update_time(double t) = 0;
    virtual void set_title(const std::string& title) = 0;
    virtual void set_time_title(const std::string& title) = 0;
    virtual void set_line_label(unsigned int which, const std::string& line) = 0;
    virtual void set_line_alpha(unsigned int which, double alpha) = 0;
    virtual void set_color_map(unsigned int which, const int color) = 0;

    virtual std::string title() = 0;
    virtual std::string line_label(unsigned int which) = 0;
    virtual double line_alpha(unsigned int which) = 0;
    virtual int color_map(unsigned int which) = 0;

    virtual void set_size(int width, int height) = 0;

    virtual void auto_scale() = 0;
    virtual double min_intensity(unsigned int which) = 0;
    virtual double max_intensity(unsigned int which) = 0;

    virtual void enable_menu(bool en = true) = 0;
    virtual void enable_grid(bool en = true) = 0;
    virtual void disable_legend() = 0;
    virtual void enable_axis_labels(bool en = true) = 0;

    QApplication* d_qApplication;
};

} /* namespace qtgui */
} /* namespace gr */

#endif /* INCLUDED_QTGUI_WATERFALL_SINK_C_H */
