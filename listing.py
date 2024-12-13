def maximum(arr,n):
  arr.sort()

  mex=arr[0]
  for i in range(1,n):
    if arr[i]>=mex :
        mex=arr[i]

  return mex

arr=[20,12,26,5,7,18]
n=len(arr)
print(maximum(arr,n))
# min=["html",29,43,"rest"]
# min[2]=35
# print(min)

# find the max of given array(do this in function after using sorting
#find mex in hackerearth