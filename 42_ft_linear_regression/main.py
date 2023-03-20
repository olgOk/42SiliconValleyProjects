import csv
from train import train
import numpy as np
data = []


# def	normalizeData(mileages, prices):
# 	x = []
# 	y = []
# 	minM = min(mileages)
# 	maxM = max(mileages)
# 	for mileage in mileages:
# 		x.append((mileage - minM) / (maxM - minM))
# 	minP = min(prices)
# 	maxP = max(prices)
# 	for price in prices:
# 		y.append((price - minP) / (maxP - minP))
# 	return (x, y)

#  def standardize(miles):
#         mu = np.mean([x for x in miles])
#         sigma = sqrt(sum([(x - mu)**2 for x in miles]))
#         X_Std = [(x - mu) / sigma for x in miles]


#open the file with prices and mileage
with open('data.csv') as csv_file:
    dialect = csv.Sniffer().sniff(csv_file.read(1024))
    csv_file.seek(0)
    csvdata = csv.reader(csv_file, dialect)
    for d in csvdata:
        data.append(d)

#working with data, remove km and price words, convert from str data type to int, normalize
data = data[1:]
prices = []
mileage =[]
for i in range(len(data)):
    mileage.append(int(data[i][0]))
    prices.append(int(data[i][1]))
# print(prices)
# print(mileage)
# miles, price = normalizeData(mileage, prices)
# print("miles")
# print(miles)
# print("price")
# print(price)

data = list(zip(mileage, prices))
b, m = train(data)
#raw_data = list(zip(mileage, prices))
b = 0
m = 0
# print("------------------")
# print(raw_data)
# print(len(raw_data))
# print("------------------")
#b, m = train(raw_data)



# normalizes data Xi = (Xi - Xaverage) / (StandartDiviation)
#calculate average
# average_price = 0
# for price in prices:
#     average_price += price 
# average_price = average_price / len(prices)
# average_mileage = 0

# for mile in mileage:
#     average_mileage += mile 
# average_mileage = average_mileage / len(mileage)

# std_deviation_price = 0
# for price in prices:
#     std_deviation_price += (price - average_price) ** 2
# std_deviation_price = std_deviation_price / len(prices)

# std_deviation_miles = 0
# for mile in mileage:
#     std_deviation_miles += (mile - average_mileage) ** 2
# std_deviation_miles = std_deviation_miles / len(mileage)

# prices_norm = []
# mileage_norm = []
# for price in prices:
#     prices_norm.append((price - average_price) / std_deviation_price)
# for mile in mileage:
#     mileage_norm.append((mile - average_mileage) / std_deviation_miles)

# data_norm = list(zip(mileage_norm, prices_norm))
# b, m = train(data_norm)
#print(data_norm)


