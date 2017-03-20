#inline math
Since Pythagoras, we know that :math:`a^2 + b^2 = c^2`.

.. The directive supports multiple equations, 
.. which should be separated by a blank line:

.. math::

   (a + b)^2 = a^2 + 2ab + b^2

   (a - b)^2 = a^2 - 2ab + b^2
   
.. aligned lines in an equation, 
.. aligned at & and separated by \\:   

.. math::

   (a + b)^2  &=  (a + b)(a + b) \\
              &=  a^2 + 2ab + b^2

.. There is also an option nowrap that 
.. prevents any wrapping of the given 
.. math in a math environment.

.. math::
   :nowrap:

   \begin{eqnarray}
      y    & = & ax^2 + bx + c \\
      f(x) & = & x^2 + 2xy + y^2
   \end{eqnarray}


.. Role for cross-referencing equations via their label.
   
.. math:: e^{i\pi} + 1 = 0
   :label: euler

Euler's identity, equation :eq:`euler`, was 
elected one of the most beautiful mathematical
formulas.

