---------------------------
Decision Feedback Equalizer
---------------------------

:gr-wiki-link:`Decision_Feedback_Equalizer`

Parameters
**********

+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|Label                    |ID                       |Description              |Data Type                |Default                  |
+=========================+=========================+=========================+=========================+=========================+
|                         |id                       |TODO                     |id                       |                         |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|Num. Taps (Forward)      |num_taps_fwd             |TODO                     |int                      |5                        |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|Num. Taps (Feedback)     |num_taps_rev             |TODO                     |int                      |3                        |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|Training Sequence        |training_sequence        |TODO                     |complex_vector           |[ ]                      |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|Training Start Tag       |training_start_tag       |TODO                     |string                   |corr_est                 |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|Adapt After Training     |adapt_after_training     |TODO                     |bool                     |True                     |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|Input Samples per Symbol |sps                      |TODO                     |int                      |                         |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+
|Adaptive Algorithm Object|alg                      |TODO                     |raw                      |                         |
+-------------------------+-------------------------+-------------------------+-------------------------+-------------------------+

Class Reference
*******************

.. tabs::

   .. group-tab:: Python
      TODO

   .. group-tab:: C++

      .. doxygengroup:: block_digital_decision_feedback_equalizer
         :content-only:
         :undoc-members:
         :private-members:
         :members:

