-------------
PlutoSDR Sink
-------------

:gr-wiki-link:`PlutoSDR_Sink`

Parameters
**********

+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|Label                    |ID                       |Description              |Data Type                |Default                  |
+=========================+=========================+=========================+=========================+=========================+
|                         |id                       |TODO                     |id                       |                         |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|Input Type               |type                     |TODO                     |enum                     |                         |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|IIO context URI          |uri                      |TODO                     |string                   |                         |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|LO Frequency             |frequency                |TODO                     |int                      |2400000000               |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|Sample Rate              |samplerate               |TODO                     |int                      |samp_rate                |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|Buffer size              |buffer_size              |TODO                     |int                      |32768                    |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|Cyclic                   |cyclic                   |TODO                     |bool                     |False                    |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|Attenuation TX1 (dB)     |attenuation1             |TODO                     |float                    |10.0                     |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|Packet Length Tag        |len_tag_key              |TODO                     |string                   |                         |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|Filter Configuration     |filter_source            |TODO                     |enum                     |'Auto'                   |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|Filter                   |filter                   |TODO                     |file_open                |                         |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|Fpass (Hz)               |fpass                    |TODO                     |float                    |0                        |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|Fstop (Hz)               |fstop                    |TODO                     |float                    |0                        |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|RF Bandwidth (Hz)        |bandwidth                |TODO                     |int                      |20000000                 |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+

Class Reference
*******************

.. tabs::

   .. group-tab:: Python
      TODO

   .. group-tab:: C++

      .. doxygengroup:: block_iio_pluto_sink
         :content-only:
         :undoc-members:
         :private-members:
         :members:

