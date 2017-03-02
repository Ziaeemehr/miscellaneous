for i in 6 7 8 9 10 
   do
      cp pl.py ${i}/data/
      cd ${i}/data/
      python pl.py
      cd ../..
   done

