def binary_search(arr, l, r, num):
    print(l, r, num)

    if (l>=r): return -1

    mid = int((l+r)/2)

    if(arr[mid] == num):
        return num
    
    elif(arr[mid]>num):
        r = mid + 1
    else:
        l = mid - 1

    return binary_search(arr, l, r, num)    

def main():
    print("hey there")

    arr = [1,2,3,4,5,6,7,8,9]

    num = binary_search(arr, 0, 9, 7)

    print(num)

if __name__=="__main__":
    main()