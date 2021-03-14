# Aproximating-Pi-using-probabilistic
To compute aproximation of Pi we will generate random points and we will use some probabilistic.
The probability for a point generated inside a square to be inside the inscribed circle of square is pi/4, since, if the radius of circle is r, then side of square will be 2*r, therefore the area of circle is pi*r*r and area of square is 4*r*r. So the probability will be area of circle / area of square = pi/4.

Let P = number of total points, and C = number of points inside circle. Then P/C should be equal pi/4.
Since we are dealing with probabilistic this will be only an aproximation and we will get pi = 4*P/C.
