def insertion_sort(input_list):
    sorted_list = []
    if not sorted_list:
        sorted_list.append(input_list[0])
        del input_list[0]
    for element in input_list:
        print("element to be sorted: {}".format(element))
        if element < sorted_list[0]:
            print("placing {} before {}".format(element, sorted_list[0]))
            sorted_list.insert(0, element)
            print(sorted_list)
        elif element > sorted_list[-1]:
            print("placing {} at the end of the list".format(element))
            sorted_list.insert(len(sorted_list), element)
        else:
            i = 0
            while element > sorted_list[i] and i < (len(sorted_list)-1):
                i += 1
            print("placing {} after {}".format(element, sorted_list[i]))
            sorted_list.insert(i, element)
            print(sorted_list)
    print("Sorted list: {}".format(sorted_list))
    return sorted_list


test_list = [17, 5, 1, 7, 9, 12, 6, 4, 2, 19]
sort_test = insertion_sort(test_list)
