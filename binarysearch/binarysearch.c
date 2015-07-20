int Binarysearch(int a[], int low, int high, int key){  
/*
	key is the searching value, low and high is the 
	two end point of the array. If the key is not in 
	the array, return -1.
*/
	if(low > high) return -1;
	int mid = (low+high)/2;  
	if(a[mid] == key) return mid;  
	else if(a[mid] > key){  
		return Binarysearch(a,low,mid-1,key);  
	}else{  
		return Binarysearch(a,mid+1,high,key);  
	}  
}
