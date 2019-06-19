cat words.txt | sed 's/[ ][ ]*/\n/g' | egrep -v "^$"|sort | uniq -c | sort -nr | awk '{print $NF,$1}'
