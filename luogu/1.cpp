#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	#endif
	int eventPt, songLoveP, lpLimit, nowLp, expLimit, nowExp, expPerSong, LVupLp, LVupExp, eventHour, targetPt;

	while(scanf("%d %d %d %d %d %d %d %d %d %d %d", &eventPt, &songLoveP, &lpLimit, &nowLp, &expLimit, &nowExp, &expPerSong, &LVupLp, &LVupExp, &eventHour, &targetPt) != EOF)
	{
		// printf("%d %d %d %d %d %d %d %d %d %d %d\n", eventPt, songLoveP, lpLimit, nowLp, expLimit, nowExp, expPerSong, LVupLp, LVupExp, eventHour, targetPt);
		int nowPt = 0, usedLoveca = 0;

		nowLp += eventHour;

		// play SIF!
		while(nowPt < targetPt)
		{
			// play a song
			if(nowLp >= songLoveP)
			{
				nowLp -= songLoveP;
				nowExp += expPerSong;

				// gain event song pt
				nowPt += eventPt;

				// Level up
				if(nowExp >= expLimit)
				{
					// exp up
					nowExp %= expLimit;
					expLimit += LVupExp;

					// lp recover
					lpLimit += LVupLp;
					nowLp += lpLimit;
				}
			}
			// use loveca
			else
			{
				nowLp += lpLimit;
				usedLoveca++;
			}
		}

		printf("%d\n", usedLoveca);
	}


	return 0;
}