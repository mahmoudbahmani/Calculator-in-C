# Calculator-in-C
A useful scientific calculator written in C code. Allows you to make basic, trigonometric, and vector operations.

--------------------------------------------------------------------------------------------------------------------

Hi, I am Calculator ( ͡° ͜ʖ ͡°), and like most of my kind, I solve math and physics related problems. I know for a fact that you are here to learn my inner workings, so I welcome you...

Here are my operations and how you can write them:

BASIC OPERATIONS ('b')
Addition--------------------x+y
Substraction----------------x-y
Multiplication--------------x*y
Division--------------------x/y
Square Root-----------------x|2
Nth Square Root-------------x|y
Power-----------------------x^y
Factorial-------------------x!

TRIGONOMETRIC FUNCTIONS ('t')
Sine--------------------tsin(x)
Cosine------------------tcos(x)
Tangent-----------------ttan(x)
Cotangent---------------tctg(x)
Secant------------------tsec(x)
Cosecant----------------tcsc(x)

INVERSE TRIGONOMETRIC FUNCTIONS ('a')
Arcine--------------------asin(x)
Arccosine-----------------acos(x)
Arctangent----------------atan(x)
Arccotangent--------------actg(x)
Arcsecant-----------------asec(x)
Arccosecant---------------acsc(x)

LOGARITHMS ('l')
Natural Log--------------------ln(x)
Base 10------------------------lg(x)

VECTOR OPERATIONS ('v')
Vector sum--------------------v[x,y,z]+[x',y',z']
Vector substraction-----------v[x,y,z]-[x',y',z']
Scalar times vector-----------v(a)[x,y,z] ("a" is a scalar)
Norm of a vector--------------v|[x,y,z]|
Dot product-------------------v[x,y,z]*[x',y',z']
Cross product-----------------v[x,y,z]x[x',y',z']

If you want to continue using your result, just write "R" for everything except vector operations, for those you write 'V', here are some examples:

5+10         |  tsin(0)     ||  v[1,1,1]+[1,1,1]               |
=15.000000   |  =0.000000   ||  =[2.000000,2.000000,2.000000]  |
R+10         |  tcos(R)     ||  v(4)V                          |
=25.000000   |  =1.000000   ||  =[8.000000,8.000000,8.000000]  |

BTW, for the irrational numbers "e" and "π", "e" stays the same, here's example:
ln(e)=1.000000
And for "π" you write the letter 'p' just like this:
tsin(p)=0.000000

Another important thing, "R", "V", "e" and "π" only work at the beginning of the operation, allow me to explain:

This is correct:   |   This is not:
5+10               |   5+10
=15.000000         |   =15.000000    
R+10               |   5+R
=25.000000         |   =15.000000

As you can see the one on the right gives you the same result as the first operation, which is not what we wanted, so be careful.

You've got this!
Remember: every time you solve problems with me a bad Wolfram loses its wings.
【 ͡~ ͜ʖ ͡°】
