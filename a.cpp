int binary_search( int a, int left, int right, int key )
{
    while( left <= right )
    {
        int mid = (left+right) / 2;
        if( a[mid] == key ) return mid; //找到了
        if( a[mid] < key ) right = mid-1; //下次找左邊的區間
        else left = mid+1; //下次找右邊的區間
    }
    return -1; //沒找到
}
int main()
{ 
    int a[11] = {1,2,17,6,7,5,8,10,15,3,19};
    sort( a, a+11 ); //一定要先排序
    int pos = binary_search( a, 0, 10, 3 );
}
