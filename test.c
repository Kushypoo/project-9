    int funArray[4][2][2];
    void createArray()
    {
        srand((unsigned)time(NULL));
        int numlist[16];
        for(int i = 0; i < 16; i++)
        {
            numlist[i] = rand()%8+1;
            //because each unique digit will be have one copy I used 2 booleans.  When both are true then reject that number.
            bool contains = false, contains2 = false;
            for(int j = 0; j < i;j++)
            {
                if(!contains)
                {
                    if(numlist[i] == numlist[j])
                    {
                        contains = true;
                    }
                }
                else
                {
                    if(numlist[i] == numlist[j])
                    {
                        contains2 = true;
                    }
                }
                //I added an additional condition here to help eliminate the same digit appearing in a pair
                if( (contains && contains2)|| (i%2==1 && numlist[i] == numlist[i-1]))
                {
                    //set i back one to overwrite the last number
                    i--;
                    break;
                }
            }
        }
    //at this point if the multi-dimensional array is just to display the numbers, you can dispense with it and use the formula here to just display the numbers.   
        for(int a = 0;a<4;a++)
        {
            for(int b = 0;b<2;b++)
            {
                for(int c = 0;c<2;c++)
                {                    
                    funArray[a][b][c]=numlist[(a*4) + (b*2) + c];
                }
            }
        }
    }
