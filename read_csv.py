import csv
import sys
with open('Consumer_Complaints.csv') as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    line_count = 0
    sys.stdout = open("data.in", "w")
    for row in csv_reader:
        line_count += 1
        if line_count == 1:
            continue
        print(f'{row[17]}')