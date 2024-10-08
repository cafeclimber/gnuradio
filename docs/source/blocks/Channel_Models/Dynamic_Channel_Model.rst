---------------------
Dynamic Channel Model
---------------------

:gr-wiki-link:`Dynamic_Channel_Model`

Parameters
**********

+------------------------------------+------------------------------------+------------------------------------+------------------------------------+------------------------------------+
|Label                               |ID                                  |Description                         |Data Type                           |Default                             |
+====================================+====================================+====================================+====================================+====================================+
|                                    |id                                  |TODO                                |id                                  |                                    |
+------------------------------------+------------------------------------+------------------------------------+------------------------------------+------------------------------------+
|Sample Rate Hz                      |samp_rate                           |TODO                                |real                                |samp_rate                           |
+------------------------------------+------------------------------------+------------------------------------+------------------------------------+------------------------------------+
|CFO Standard Deviation Hz per sample|cfo_stdev                           |TODO                                |real                                |0.01                                |
+------------------------------------+------------------------------------+------------------------------------+------------------------------------+------------------------------------+
|Max CFO Bound Hz                    |cfo_maxdev                          |TODO                                |real                                |1e3                                 |
+------------------------------------+------------------------------------+------------------------------------+------------------------------------+------------------------------------+
|SRO Standard Deviation Hz per sample|sro_stdev                           |TODO                                |real                                |0.01                                |
+------------------------------------+------------------------------------+------------------------------------+------------------------------------+------------------------------------+
|Max SRO Bound Hz                    |sro_maxdev                          |TODO                                |real                                |1e3                                 |
+------------------------------------+------------------------------------+------------------------------------+------------------------------------+------------------------------------+
|White Noise Amplitude               |noise_amp                           |TODO                                |real                                |1.0                                 |
+------------------------------------+------------------------------------+------------------------------------+------------------------------------+------------------------------------+
|Num Sinusoids (SoS model)           |N                                   |TODO                                |int                                 |8                                   |
+------------------------------------+------------------------------------+------------------------------------+------------------------------------+------------------------------------+
|Max Doppler Freq (Hz)               |fD                                  |TODO                                |real                                |2.0                                 |
+------------------------------------+------------------------------------+------------------------------------+------------------------------------+------------------------------------+
|LOS Model                           |LOS                                 |TODO                                |enum                                |                                    |
+------------------------------------+------------------------------------+------------------------------------+------------------------------------+------------------------------------+
|Rician factor (K)                   |K                                   |TODO                                |real                                |4.0                                 |
+------------------------------------+------------------------------------+------------------------------------+------------------------------------+------------------------------------+
|Seed                                |seed                                |TODO                                |int                                 |0                                   |
+------------------------------------+------------------------------------+------------------------------------+------------------------------------+------------------------------------+
|PDP Delays (samp)                   |delays                              |TODO                                |real_vector                         |0.0,0.1,1.3                         |
+------------------------------------+------------------------------------+------------------------------------+------------------------------------+------------------------------------+
|PDP Magnitudes                      |mags                                |TODO                                |real_vector                         |1,0.99,0.97                         |
+------------------------------------+------------------------------------+------------------------------------+------------------------------------+------------------------------------+
|Num Taps                            |ntaps                               |TODO                                |int                                 |8                                   |
+------------------------------------+------------------------------------+------------------------------------+------------------------------------+------------------------------------+

Class Reference
*******************

.. tabs::

   .. group-tab:: Python
      TODO

   .. group-tab:: C++

      .. doxygengroup:: block_channels_dynamic_channel_model
         :content-only:
         :undoc-members:
         :private-members:
         :members:

