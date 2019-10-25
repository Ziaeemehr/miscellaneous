% save to file
x = 0:.1:1;
A = [x; exp(x)];
fileID = fopen('exp.txt','w');
fprintf(fileID,'%6s %12s\n','x','exp(x)');
fprintf(fileID,'%6.2f %12.8f\n',A);
fclose(fileID);

% save figure
figure
surf(peaks)
savefig('PeaksFile.fig')
% opening
openfig('PeaksFile.fig');

% save fig with format
x = [2 4 7 2 4 5 2 5 1 4];
bar(x);
saveas(gcf,'Barchart.png')
saveas(gcf,'Barchart','epsc')

% variable file name
file_name = sprintf('picture_%i.jpeg', i);
% or:
file_name = strcat('picture_', num2str(i), '.jpeg');

%  Run several matlab instances in a nohup bash scrip
https://stackoverflow.com/questions/18510304/run-several-matlab-instances-in-a-nohup-bash-script
Compiling all suggestions and ideas you could try these:

#!/bin/bash
ssh user@ipaddress "
cd folder1/
nohup matlab -nodesktop -nodisplay < mycode.m > output.txt 2>&1 &
cd folder2/
nohup matlab -nodesktop -nodisplay < mycode.m > output.txt 2>&1 &
"
Or

#!/bin/bash
ssh user@ipaddress "
cd folder1/
nohup matlab -nodesktop -nodisplay -r 'mycode;quit;' < /dev/null  > output.txt 2>&1 &
cd folder2/
nohup matlab -nodesktop -nodisplay -r 'mycode;quit;' < /dev/null  > output.txt 2>&1 &
"
Or

#!/bin/bash
ssh user@ipaddress "
cd folder1/
screen -dm matlab -nodesktop -nodisplay < mycode.m > output.txt 2>&1
cd folder2/
screen -dm matlab -nodesktop -nodisplay < mycode.m > output.txt 2>&1
"
Or

#!/bin/bash
ssh user@ipaddress "
cd folder1/
screen -dm matlab -nodesktop -nodisplay -r 'mycode;quit;' < /dev/null  > output.txt 2>&1
cd folder2/
screen -dm matlab -nodesktop -nodisplay -r 'mycode;quit;' < /dev/null  > output.txt 2>&1
"

