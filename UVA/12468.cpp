#include <stdio.h>
int main()
{
    const int INPUT_END = -1;
    int current_see = 0, want_to_see = 0;
    scanf("%d %d", &current_see, &want_to_see);
    while (current_see != INPUT_END && want_to_see != INPUT_END)
    {
            int countdown=0;
			countdown=current_see-want_to_see;if(countdown<0)countdown+=100;
			int countup=0;
			countup=want_to_see-current_see;if(countup<0)countup+=100;
			if(countdown<countup)
				printf("%d\n",countdown);
			else
				printf("%d\n",countup);
            scanf("%d %d", &current_see, &want_to_see);
    }
    return 0;
}
