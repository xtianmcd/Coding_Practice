years = [] #stores all years of birth of customers 

cust_num = 1 #gives each customer a number
num = input("How many cards do you need to check?") #gives number of cards
for i in range(int(num)): #gets year of birth off card from bartender
    cust_str = "What year was customer "+ str(cust_num)+ " born?"
    report_DOB = input(cust_str)
    years.append(int(report_DOB))
    cust_num += 1
    
current_year = input("What is the current year?")


cust_num = 1
for i in range(int(num)): #calculates age and verifies legality of customer to drink
    age = int(current_year) - (years[i])
    if age >= 21:
        print("Customer ", cust_num, " is old enough to party. Serve em up.")
    else:
        print("Customer ", cust_num, " is too young. Do not serve.")
    print("Customer", cust_num, " is ", age, " years old.")
    cust_num += 1
