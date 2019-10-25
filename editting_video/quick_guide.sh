# slice video in terminal
ffmpeg -i input.mp4 -ss 00:00:03 -t 00:00:08 -async 1 cut.mp4
# start at 3s end at 8s

# join videos in terminal
for f in $(ls *.mp4); do
    ffmpeg -i $f -c copy -bsf:v h264_mp4toannexb -f mpegts $f.ts
done

CONCAT=$(echo $(ls *.ts) | sed -e "s/ /|/g")

ffmpeg -i "concat:$CONCAT" -c copy -bsf:a aac_adtstoasc output.mp4

rm *.ts



#removing noise from audio file
# How To Do Noise Reduction Using ffmpeg And sox
http://www.zoharbabin.com/how-to-do-noise-reduction-using-ffmpeg-and-sox/


## 1. Split the audio and video streams into 2 seperate files:
# The VIDEO stream: 
ffmpeg -i input.mp4 -vcodec copy -an tmpvid.mp4

# The AUDIO stream: 
ffmpeg -i input.mp4 -acodec pcm_s16le -ar 128k -vn tmpaud.wav 

# =============================================================
# use auacity to clean the noise:
# 1. Select the “silent” section of your audio, where it’s just noise.
# 2. Go to the Effects menu and click Noise Removal.
# 3. Click Get Noise Profile.
# 4. Select all of the audio from which you want that background noise removed.
# 5. Go to the Effects menu and click Noise Removal.
# 6. Adjust the settings if necessary (defaults are fine) and click OK.
# 7. Listen to ensure your audio doesn’t sound like it’s underwater.
# 8. save with name 
tmpaud-clean.wav
# =============================================================


## 2. Generate a sample of noise from the audio of the file:
ffmpeg -i input.mp4 -acodec pcm_s16le -ar 128k -vn -ss 00:00:00.0 -t 00:00:00.5 noiseaud.wav

# -ss: the time offset from beginning. (h:m:s.ms).
# -t duration: the duration (h:m:s.ms) of audio segment to cut that represents the noise.
# Choose a segment of the audio where there’s no speech, only noise (e.g. speaker was silent for a sec).

## 3. Generate a noise profile in sox:
sox noiseaud.wav -n noiseprof noise.prof

## 4. Clean the noise samples from the audio stream:
sox tmpaud.wav tmpaud-clean.wav noisered noise.prof 0.21
# Change 0.21 to adjust the level of sensitivity in the sampling rates 
# (I found 0.2-0.3 often provides best result).

## 5. Merge the audio and video streams back together:
ffmpeg -i tmpvid.mp4 -i tmpaud-clean.wav -map 0:v -map 1:a -c:v copy -c:a aac -b:a 128k out.mp4
