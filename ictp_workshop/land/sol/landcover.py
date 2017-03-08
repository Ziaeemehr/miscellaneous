#!/usr/bin/env python
import numpy as np
import matplotlib.pyplot as pl
import readline
import argparse
from matplotlib import colors

# http://www.landcover.org/data/landcover/

# Information
# Image Size: 				43200 Pixels 21600 Lines
# Quantization:			    8-bit unsigned integer
# Output Georeferenced Units: LONG/LAT E019
# Projection:    				Geographic (geodetic)
# Earth Ellipsoid:			Sphere, rad 6370997 m
# Upper Left Corner:			180d00'00.00" W Lon90d00'00.00" N Lat
# Lower Right Corner:			180d00'00.00" E Lon 90d00'00.00" S Lat
# Pixel Size (in Degrees):	0.00833 Lon 0.00833 Lat
# (Equivalent Deg,Min,Sec):	0d00'30.00"0d00'30.00"
# UpLeftX:					-180
# UpLeftY:      				90
# LoRightX:        			180
# LoRightY:      				-90

PX_per_DEG = 120.

LATPX = 21600
LONPX = 43200

PLOT = False

legend = { # r g b
0	: " 0 Water",
1	: " 1 Evergreen Needleleaf Forest",
2	: " 2 Evergreen Broadleaf Forest",
3	: " 3 Deciduous Needleleaf Forest",
4	: " 4 Deciduous Broadleaf Forest",
5	: " 5 Mixed Forest",
6	: " 6 Woodland",
7	: " 7 Wooded Grassland",
8	: " 8 Closed Shrubland",
9	: " 9 Open Shrubland",
10	: "10 Grassland",
11	: "11 Cropland",
12	: "12 Bare Ground",
13	: "13 Urban and Built",
}

step_cmap = colors.ListedColormap(
	[
	( 68/255.,  79/255., 137/255.),
	(  1/255., 100/255.,   0/255.),
	(  1/255., 130/255.,   0/255.),
	(151/255., 191/255.,  71/255.),
	(  2/255., 220/255.,   0/255.),
	(  0/255., 255/255.,   0/255.),
	(146/255., 174/255.,  47/255.),
	(220/255., 206/255.,   0/255.),
	(255/255., 173/255.,   0/255.),
	(255/255., 251/255., 195/255.),
	(140/255.,  72/255.,   9/255.),
	(247/255., 165/255., 255/255.),
	(255/255., 199/255., 174/255.),
	(  0/255., 255/255., 255/255.),
	]
	,N=14)

def toLon(px):
	return -180. + px / PX_per_DEG

def toLat(px):
	return   90. - px / PX_per_DEG

def fromLat(deg):
	return int(PX_per_DEG * ( 90. - deg))

def fromLon(deg):
	return int(PX_per_DEG * (180. + deg))

## done_cbar = False

def plot(grid,latpx,lonpx,ax1,ax2,R=1000):
		if not PLOT:
			return
		print "Preparing plot."
		lonmin,lonmax = lonpx-R, lonpx+R
		latmin,latmax = latpx-R, latpx+R

		im1 = ax1.imshow(grid[latmin:latmax,lonmin:lonmax],
		           cmap=step_cmap,
		           interpolation='nearest',
		           extent=(toLon(lonmin),toLon(lonmax),toLat(latmax),toLat(latmin)))
		im1.set_norm(colors.Normalize(vmin=0,vmax=13))
		im2 = ax2.imshow(local_cell(grid,latpx,lonpx),
		           cmap=step_cmap,
		           interpolation='nearest')
		im2.set_norm(colors.Normalize(vmin=0,vmax=13))


##		if not done_cbar:
##			do_cbar()

		print "Showing plot."
		pl.draw()
		pl.pause(0.1)
		print "Done!"


## def do_cbar():
## 	cbar = pl.colorbar()
## 	#cbar.ax.get_yaxis().set_ticks([])
## 	for j, lab in legend.iteritems():
## 	    cbar.ax.text(.5, j, lab, ha='center', va='center',transform=cbar.ax.transAxes)
## 	#cbar.ax.get_yaxis().labelpad = 15
## 	#cbar.ax.set_ylabel('# of contacts', rotation=270)
## 	done_cbar = True


def local_cell(grid,latpx,lonpx):
	N = 5
	cell = grid[latpx-N:latpx+N+1,lonpx-N:lonpx+N+1]
	return cell


def main():
	parser = argparse.ArgumentParser(description='Plot land cover around a coordinate.')
	parser.add_argument('-p','--plot', action='store_true',
	                   default=False,
	                   help='Use coloured map.')

	args = parser.parse_args()
	global PLOT
	PLOT = args.plot



	print "Loading data file."

	#raw = np.fromfile('gl-latlong-1km-landcover.bsq',dtype=np.uint8)
	#grid = raw.reshape((LATPX,LONPX))

	grid = np.memmap('gl-latlong-1km-landcover.bsq', dtype=np.uint8, mode='r', shape=(LATPX,LONPX))

	print "Done!"

	if PLOT:

		pl.ion()

		ax1 = pl.subplot('121')
		ax1.set_xlabel('Longitude [deg]')
		ax1.set_ylabel('Latitude [deg]')


		ax2 = pl.subplot('122')
		ax2.xaxis.set_visible(False)
		ax2.yaxis.set_visible(False)

	while True:
		try:
			lat,lon = raw_input("LAT LON ").rstrip().split()
			latpx,lonpx = fromLat(float(lat)), fromLon(float(lon))
		except:
			break
		cover = grid[latpx,lonpx]
		local = local_cell(grid,latpx,lonpx)

		surrounds = [ legend[x] for x in set( np.unique(local) ) - set([cover]) ]
		text = 'Lat %s Lon %s\n==> %s <==\n%s' % (lat,lon,legend[cover],
		                                           '\n'.join(surrounds))
		print text

		print local

		if PLOT:
			ax1.plot([lon],[lat],'ro')
			#ax2.plot(0.5,0.5,'ro',transform=ax2.transAxes)
			ax2.set_title(text,fontsize=6)
			plot(grid,latpx,lonpx,ax1,ax2)

		print '\n'

	if PLOT:
		pl.ioff()

if __name__ == '__main__':
	main()
