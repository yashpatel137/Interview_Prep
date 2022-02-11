int getPivotElement(int *array, int left, int right){
   if (left>right)  
       return -1;
    
   if (left == right) 
       return left;
  
   int middle = (left + right)/2;
    
   if (middle < right && array[middle] > array[middle + 1])
       return middle;
 
   if (middle > left && array[middle] < array[middle - 1])
       return middle-1;
     
   if (array[left] >= array[middle]){
       return getPivotElement(array, left, middle-1);
   } else {
       return getPivotElement(array, middle + 1, right);
   }
}
 