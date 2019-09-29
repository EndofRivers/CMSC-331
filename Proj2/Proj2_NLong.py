import csv

f = open('test-data.csv')
csv_f = csv.reader(f)

#Variables
distance_summation = 0.00 # Summation of all successful shots
used_records = 0 # Summation of all records that were used in the calculation
index_errors = 0 # Number of Index Errors caught
value_errors = 0 # Number of Value Errors caught
total_records = 0 # Number of total records in the .csv file
zero_division_errors = 0 # Number of Zero Division Errors caught

next(csv_f, None) # Skip the header of the file

for row in csv_f:
    try:
        if len(row) < 5:
            raise IndexError
        try:
            distance_summation += float(row[2])
            if int(row[4]) is 0:
                   distance_summation -= float(row[2])
        except ValueError:
            value_errors += 1
        else:
            if int(row[4]) is 1:
                used_records += 1
    except IndexError:
        index_errors += 1
    finally:
        total_records += 1

try:
    average_shot_distance = distance_summation / used_records # Average of all successful shots
except ZeroDivisionError:
    zero_division_errors += 1
finally:
    f.close()

#Final Output
print 'Total number of records: {}'.format(total_records)
print 'The number of records used for calculation: {}'.format(used_records)
print 'The average successful shot distance: {0:.2f}'.format(average_shot_distance)
print 'Number of index errors: {}'.format(index_errors)
print 'Number of value errors: {}'.format(value_errors)
print 'Number of division by zero errors: {}'.format(zero_division_errors)

