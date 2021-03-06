%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% File:          mc103.m
%
% Dimension:     3
% Domain:        Three-dimensional bar.
% Boundary:      Two dirichlet faces at the left end of the bar.
%
% Notes:         The elements are split into three material types (0,1,2).
%                This is basically to tag the six tetrahedra in the middle
%                section (type 1) and the six at the right end (type 2),
%                for applying (body) forces.  All of the other elements
%                are marked as the third type (type 0).
%
%                The boundary faces are split into four types.
%                The left end of the bar is Dirichlet (type 1), so it fixes 
%                the bar to an imaginary wall on the left.  The rest of the 
%                boundary faces are normal Neumann (type 2), except for
%                the face in the middle of the bar on the top (type 4),
%                and the face at the right end on the bottom (type 6).
%                These two special face types are for applying 
%                (traction) forces.
%
% rcsid="$Id: mc103.m,v 1.3 2010/08/12 05:16:44 fetk Exp $"
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% MC = < Manifold Code >
%%% Copyright (C) 1994-- Michael Holst 
%%%
%%% This library is free software; you can redistribute it and/or 
%%% modify it under the terms of the GNU Lesser General Public 
%%% License as published by the Free Software Foundation; either  
%%% version 2.1 of the License, or (at your option) any later version. 
%%%
%%% This library is distributed in the hope that it will be useful, 
%%% but WITHOUT ANY WARRANTY; without even the implied warranty of             
%%% MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
%%% Lesser General Public License for more details. 
%%%
%%% You should have received a copy of the GNU Lesser General Public 
%%% License along with this library; if not, write to the Free Software  
%%% Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA   
%%%
%%% rcsid="$Id: mc103.m,v 1.3 2010/08/12 05:16:44 fetk Exp $"
%%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

mcsf_begin=1;

      dim=3;         % intrinsic manifold dimension
    dimii=3;         % imbedding manifold dimension
 vertices=44;        % number of vertices
simplices=60;        % number of simplices

vert=[
%-------- ---- ----------------- ----------------- -----------------
% Vert-ID Chrt X-Coordinate      Y-Coordinate      Z-Coordinate
%-------- ---- ----------------- ----------------- -----------------
0         0     0.0000000000e+00  0.0000000000e+00  0.0000000000e+00
1         0     0.0000000000e+00  1.0000000000e+00  0.0000000000e+00
2         0     0.0000000000e+00  0.0000000000e+00  1.0000000000e+00
3         0     0.0000000000e+00  1.0000000000e+00  1.0000000000e+00
4         0     1.0000000000e+00  0.0000000000e+00  0.0000000000e+00
5         0     1.0000000000e+00  1.0000000000e+00  0.0000000000e+00
6         0     1.0000000000e+00  0.0000000000e+00  1.0000000000e+00
7         0     1.0000000000e+00  1.0000000000e+00  1.0000000000e+00
8         0     2.0000000000e+00  0.0000000000e+00  0.0000000000e+00
9         0     2.0000000000e+00  1.0000000000e+00  0.0000000000e+00
10        0     2.0000000000e+00  0.0000000000e+00  1.0000000000e+00
11        0     2.0000000000e+00  1.0000000000e+00  1.0000000000e+00
12        0     3.0000000000e+00  0.0000000000e+00  0.0000000000e+00
13        0     3.0000000000e+00  1.0000000000e+00  0.0000000000e+00
14        0     3.0000000000e+00  0.0000000000e+00  1.0000000000e+00
15        0     3.0000000000e+00  1.0000000000e+00  1.0000000000e+00
16        0     4.0000000000e+00  0.0000000000e+00  0.0000000000e+00
17        0     4.0000000000e+00  1.0000000000e+00  0.0000000000e+00
18        0     4.0000000000e+00  0.0000000000e+00  1.0000000000e+00
19        0     4.0000000000e+00  1.0000000000e+00  1.0000000000e+00
20        0     5.0000000000e+00  0.0000000000e+00  0.0000000000e+00
21        0     5.0000000000e+00  1.0000000000e+00  0.0000000000e+00
22        0     5.0000000000e+00  0.0000000000e+00  1.0000000000e+00
23        0     5.0000000000e+00  1.0000000000e+00  1.0000000000e+00
24        0     6.0000000000e+00  0.0000000000e+00  0.0000000000e+00
25        0     6.0000000000e+00  1.0000000000e+00  0.0000000000e+00
26        0     6.0000000000e+00  0.0000000000e+00  1.0000000000e+00
27        0     6.0000000000e+00  1.0000000000e+00  1.0000000000e+00
28        0     7.0000000000e+00  0.0000000000e+00  0.0000000000e+00
29        0     7.0000000000e+00  1.0000000000e+00  0.0000000000e+00
30        0     7.0000000000e+00  0.0000000000e+00  1.0000000000e+00
31        0     7.0000000000e+00  1.0000000000e+00  1.0000000000e+00
32        0     8.0000000000e+00  0.0000000000e+00  0.0000000000e+00
33        0     8.0000000000e+00  1.0000000000e+00  0.0000000000e+00
34        0     8.0000000000e+00  0.0000000000e+00  1.0000000000e+00
35        0     8.0000000000e+00  1.0000000000e+00  1.0000000000e+00
36        0     9.0000000000e+00  0.0000000000e+00  0.0000000000e+00
37        0     9.0000000000e+00  1.0000000000e+00  0.0000000000e+00
38        0     9.0000000000e+00  0.0000000000e+00  1.0000000000e+00
39        0     9.0000000000e+00  1.0000000000e+00  1.0000000000e+00
40        0     1.0000000000e+01  0.0000000000e+00  0.0000000000e+00
41        0     1.0000000000e+01  1.0000000000e+00  0.0000000000e+00
42        0     1.0000000000e+01  0.0000000000e+00  1.0000000000e+00
43        0     1.0000000000e+01  1.0000000000e+00  1.0000000000e+00
];

simp=[
%-------- ---- ---- ------------------- ---------------------------------------
% Simp-ID Grp  Mat  Face-Types          Vertex-Numbers
%-------- ---- ---- ------------------- ---------------------------------------
0         0    0    0    1    2    2    0 4 1 2
1         0    0    0    2    0    2    1 4 5 3
2         0    0    0    1    0    0    1 4 3 2
3         0    0    2    2    0    0    3 4 6 2
4         0    0    0    0    0    0    5 4 6 3
5         0    0    2    2    0    0    5 6 7 3
6         0    0    2    0    0    2    5 4 8 6
7         0    0    0    0    0    0    5 6 8 7
8         0    0    0    2    0    2    5 8 9 7
9         0    0    0    0    0    0    9 8 10 7
10        0    0    2    2    0    0    9 10 11 7
11        0    0    2    0    0    2    9 8 12 10
12        0    0    0    0    0    0    9 10 12 11
13        0    0    0    2    0    2    9 12 13 11
14        0    0    0    0    0    0    13 12 14 11
15        0    0    2    2    0    0    13 14 15 11
16        0    0    2    0    0    2    13 12 16 14
17        0    0    0    0    0    0    13 14 16 15
18        0    0    0    2    0    2    13 16 17 15
19        0    0    0    0    0    0    17 16 18 15
20        0    0    2    2    0    0    17 18 19 15
21        0    0    2    0    0    2    17 16 20 18
22        0    0    0    0    0    0    17 18 20 19
23        0    0    0    2    0    2    17 20 21 19
24        0    0    0    0    0    0    21 20 22 19
25        0    0    2    2    0    0    21 22 23 19
26        1    1    2    0    0    2    21 20 24 22
27        1    1    0    0    0    0    21 22 24 23
28        1    1    0    4    0    2    21 24 25 23
29        1    1    0    0    0    0    25 24 26 23
30        1    1    2    4    0    0    25 26 27 23
31        0    0    2    0    0    2    25 24 28 26
32        0    0    0    0    0    0    25 26 28 27
33        0    0    0    2    0    2    25 28 29 27
34        0    0    0    0    0    0    29 28 30 27
35        0    0    2    2    0    0    29 30 31 27
36        0    0    2    0    0    2    29 28 32 30
37        0    0    0    0    0    0    29 30 32 31
38        0    0    0    2    0    2    29 32 33 31
39        0    0    0    0    0    0    33 32 34 31
40        0    0    2    2    0    0    33 34 35 31
41        0    0    2    0    0    2    33 32 36 34
42        0    0    0    0    0    0    33 34 36 35
43        0    0    0    2    0    2    33 36 37 35
44        0    0    0    0    0    0    37 36 38 35
45        0    0    2    2    0    0    37 38 39 35
46        2    2    6    0    0    2    37 36 40 38
47        2    2    0    0    0    0    37 38 40 39
48        2    2    0    2    0    2    37 40 41 39
49        2    2    0    0    0    2    41 40 42 39
50        2    2    2    2    0    2    41 42 43 39
51        0    0    2    0    0    2    8 6 10 7
52        2    2    2    0    0    6    40 38 42 39
53        0    0    2    0    0    2    36 34 38 35
54        0    0    2    0    0    2    32 30 34 31
55        0    0    2    0    0    2    28 26 30 27
56        1    1    2    0    0    2    24 22 26 23
57        0    0    2    0    0    2    20 18 22 19
58        0    0    2    0    0    2    16 14 18 15
59        0    0    2    0    0    2    12 10 14 11
];

mcsf_end=1;

