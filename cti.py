import csv
import os
import sys

folder=sys.argv[1]
if not(folder.endswith('/')):
    folder=folder+'/'
os.rename(folder+'constant_to_int.csv', folder+'constant_to_int.csv.bak')

csv_in = open(folder+'constant_to_int.csv.bak', 'rb')
csv_out = open(folder+'constant_to_int.csv', 'wb')


writer = csv.writer(csv_out, delimiter='\t')
for row in csv.reader(csv_in, delimiter='\t'):
    number = int(row[1])
    while (number >= 2147483647) or (number <= -2147483647):
        number /= 10
    row[1] = str(number)
    writer.writerow(row)
csv_in.close()
csv_out.close()
