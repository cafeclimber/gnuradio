-----------------
FMComms2/3/4 Sink
-----------------

:gr-wiki-link:`FMComms2/3/4_Sink`

Parameters
**********

+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|Label                    |ID                       |Description              |Data Type                |Default                  |
+=========================+=========================+=========================+=========================+=========================+
|                         |id                       |TODO                     |id                       |                         |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|Input Type               |type                     |TODO                     |enum                     |                         |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|IIO context URI          |uri                      |TODO                     |string                   |local:                   |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|LO Frequency             |frequency                |TODO                     |int                      |2400000000               |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|Sample Rate              |samplerate               |TODO                     |int                      |samp_rate                |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|RF Bandwidth             |bandwidth                |TODO                     |int                      |20000000                 |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|Buffer size              |buffer_size              |TODO                     |int                      |32768                    |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|TX1 Enabled              |tx1_en                   |TODO                     |bool                     |True                     |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|TX2 Enabled              |tx2_en                   |TODO                     |bool                     |True                     |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|Cyclic                   |cyclic                   |TODO                     |bool                     |False                    |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|RF Port Select           |rf_port_select           |TODO                     |enum                     |'A'                      |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|Attenuation TX1 (dB)     |attenuation1             |TODO                     |float                    |10.0                     |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|Attenuation TX2 (dB)     |attenuation2             |TODO                     |float                    |10.0                     |
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

      .. doxygengroup:: block_iio_fmcomms2_sink
         :content-only:
         :undoc-members:
         :private-members:
         :members:

