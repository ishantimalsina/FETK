%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% File:          mc8.m
%
% Dimension:     2 (imbedded in 3)
% Domain:        Icosahedron, unit normals pointing OUT
% Boundary:      ?
%
% rcsid="$Id: mc8.m,v 1.4 2010/08/12 05:17:23 fetk Exp $"
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
%%% rcsid="$Id: mc8.m,v 1.4 2010/08/12 05:17:23 fetk Exp $"
%%% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

mcsf_begin=1;

      dim=2;         % intrinsic manifold dimension
    dimii=3;         % imbedding manifold dimension
 vertices=12;        % number of vertices
simplices=20;        % number of simplices

vert=[
%-------- ---- ----------------- ----------------- -----------------
% Vert-ID Chrt X-Coordinate      Y-Coordinate      Z-Coordinate
%-------- ---- ----------------- ----------------- -----------------
0         0    -5.2573110000e-01  0.0000000000e+00  8.5065080000e-01
1         0     5.2573110000e-01  0.0000000000e+00  8.5065080000e-01
2         0    -5.2573110000e-01  0.0000000000e+00 -8.5065080000e-01
3         0     5.2573110000e-01  0.0000000000e+00 -8.5065080000e-01
4         0     0.0000000000e+00  8.5065080000e-01  5.2573110000e-01
5         0     0.0000000000e+00  8.5065080000e-01 -5.2573110000e-01
6         0     0.0000000000e+00 -8.5065080000e-01  5.2573110000e-01
7         0     0.0000000000e+00 -8.5065080000e-01 -5.2573110000e-01
8         0     8.5065080000e-01  5.2573110000e-01  0.0000000000e+00
9         0    -8.5065080000e-01  5.2573110000e-01  0.0000000000e+00
10        0     8.5065080000e-01 -5.2573110000e-01  0.0000000000e+00
11        0    -8.5065080000e-01 -5.2573110000e-01  0.0000000000e+00
];

simp=[
%-------- ---- ---- ------------------- ---------------------------------------
% Simp-ID Grp  Mat  Face-Types          Vertex-Numbers
%-------- ---- ---- ------------------- ---------------------------------------
0         0    0    0    0    0         0 1 4
1         0    0    0    0    0         0 4 9
2         0    0    0    0    0         9 4 5
3         0    0    0    0    0         4 8 5
4         0    0    0    0    0         4 1 8
5         0    0    0    0    0         8 1 10
6         0    0    0    0    0         8 10 3
7         0    0    0    0    0         5 8 3
8         0    0    0    0    0         5 3 2
9         0    0    0    0    0         2 3 7
10        0    0    0    0    0         7 3 10
11        0    0    0    0    0         7 10 6
12        0    0    0    0    0         7 6 11
13        0    0    0    0    0         11 6 0
14        0    0    0    0    0         0 6 1
15        0    0    0    0    0         6 10 1
16        0    0    0    0    0         9 11 0
17        0    0    0    0    0         9 2 11
18        0    0    0    0    0         9 5 2
19        0    0    0    0    0         7 11 2
];

mcsf_end=1;

