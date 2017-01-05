 #!/bin/bash
for i in {1..194}
    do
        convert -density 300 ${i}.pdf -quality 90 ${i}.png
    done