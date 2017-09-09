import numpy as np 
import os
import glob
import sys

g   = [float(sys.argv[1])]
tau = np.arange(0.5, 15, 0.1)

ni = len(g)
nj = len(tau)
os.chdir("./../data/f/")

for i in range(ni):
    for j in range(nj):
        old_name = "Cor-"+str("%.6f"%g[i])+"-"+str("%.6f"%tau[j])+".png"
        new_name = "image"+str("%05d"%j)+".png"
        os.rename(old_name, new_name)

os.system("ffmpeg -f image2 -r 2 -i image%05d.png -vcodec mpeg4 -y movie.mp4")


ffmpeg -f image2 -r 10 -i image%05d.png -vcodec mpeg4 -y movie.mp4
ffmpeg -f image2 -i image%d.jpg -vcodec mpeg4 -b 800k video.avi
ffmpeg -f image2 -i image%d.jpg -vcodec libx264 -b 800k video.avi



ffmpeg -f image2 -r 10 -i image%05d.png -vcodec mpeg4 -b 1000k movie.avi
