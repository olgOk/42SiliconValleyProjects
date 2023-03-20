def predict_price(x, b, m):
    return -m * x + b

def calculate_sum(b0, m0, data):
    sum0 = float(0.0)
    sum1 = float(0.0)
    for d in data:
        mile = float(d[0])
        act_price = float(d[1])
        # print("miles = " +str(mile)+"prce = "+str(price))
        # print(d)
        ### difference between theopretical and actual prices
        sum0 += (act_price - predict_price(mile, b0, m0)) 
        # print("sum0 in calculate sum is " +str(sum0))
        ### 
        sum1 += ((act_price - predict_price(mile, b0, m0)) * mile)
    return sum0, sum1

# def calculate_error(b0, m0, data):
#     epsilon = (estimate_price( , b0, m0) - ) ** 2

def calculate_coefficients(b0, m0, learn_rate, data):
    m = float(len(data))
    #print(m)
    b = b0
    w = m0
    index = 0
    while (index<1):
        # sum0, sum1 = calculate_sum(b0, m0, data)
        sum0, sum1 = calculate_sum(b, w, data)

        # print("Sum0 = " + str(sum0))
        # print("Sum1 = " + str(sum1))
        #error = calculate_error()
        tmp_b = float( sum0)
        tmp_m = float(2 * learn_rate * sum1 / m)
        # print(tmp_b)
        # print(tmp_m)
        # print("tmp_b = " + str(tmp_b))
        # print("tmp_m = " + str(tmp_m))
       
        b += tmp_b 
        w -= tmp_m
        # print("in iteration # "+ str(index)+ "theta0 = " + str(theta0))
        # print("theta1 = " + str(theta1))
        index += 1
    # print(theta0, theta1)
    return b, w

def train(data):
    b_start = float(0.0)
    m_start = float(0.0)
    n = float(len(data))
    tmp = 0.0
    for d in data[0]:
        tmp += (d) ** 2
    learning_rate = n / (2 * tmp)
    print(learning_rate)
    b = 0.0
    m = 0.0
    # print(type(b_start))
    # print(type(m_start))
    # print(type(learning_rate))
    # print(type(b))
    # print(type(m))
    b, m = calculate_coefficients(b_start, m_start, 0.017, data)
    print("b and m in train function: " + str(b) + "  " + str(m))
    return b, m