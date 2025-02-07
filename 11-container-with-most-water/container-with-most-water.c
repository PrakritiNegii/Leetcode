int maxArea(int* height, int heightSize) 
 {
  int water = 0, max = 0;
  for(int i=0, j=heightSize-1; i<j;)
   {
    if(height[i]<height[j])
     {
      water = height[i]*(j-i);
      if(max==0) max = water;
      i++;
     }
    else
     {
      water = height[j]*(j-i);
      if(max==0) max = water;
      j--;
     }
    if(max<water) max = water;
   }
  return max;
 }
//   int max = 0, water = 0, pole=0;
//   for(int i=0; i<heightSize; i++)
//    {
//     if(height[i]<=pole) 
//       continue;
//     for(int j=i+1; j<heightSize; j++)
//      {
//       if(height[i]<height[j]) 
//        {
//         pole = height[i];
//         water = pole * (j-i);
//        }
//       else
//        {
//         pole = height[j];
//         water = pole * (j-i);
//        }

//       if(max<water)
//         max = water;
//      }
//    }
//   return max;
// }