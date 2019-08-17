// bitmask_타일채우기_2718

- 이해한 문제내용
	- 4\*N 타일을 1\*2, 2*1 의 도미노로 채울 수 있는 경우의 수 출력

- 접근 방식
	- 하나씩 무작위로 그려보고 있다 포기한 후 규칙을 찾을려고 N이 2의 배수인지 아닌지 확인하는 방식으로 푸는가 싶었지만 감이 잡히지 않아서 풀이를 봄
	- <http://joonas-yoon.blogspot.com/2016/03/2718.html> 해당 풀이를 참고	- 한줄씩 채워가는 형태로 할 때 row가 4로 고정되어 있으므로 채워진 타일을 비트로 1이라 표기할 때 나올 수 있는 경우는 0000 0011 0110 1001 1100 

- 해당 풀이에 있었던 그림 => 그림으로 이해할 수 있었다

![한줄씩](https://2.bp.blogspot.com/-P7ubP6ACg24/Wb1g6ENQWuI/AAAAAAAACSA/3OK8mHEWUYoKinYaFRueXgySsbE41XHjACLcBGAs/s1600/2718_1.png)

![각케이스당경우](https://2.bp.blogspot.com/-Pevn_DUSVkU/VugVTUbwe5I/AAAAAAAAAxw/TD-8KMGayR0JgdPe0DfrZgepZFdn0hl3w/s640/%25EA%25B7%25B8%25EB%25A6%25BC2.png)


- 메모이제이션을 활용하여 중복되는 경우 불필요한 연산하지 않도록
- swtich 문으로 각 케이스 당 경우의 수를 계산

- 어려웠던 점
	- 처음 위와 같은 풀이를 아예 생각을 못했다
	- 예외에 대한 생각
	- 구현자체는 어렵지 않았는데 풀이과정을 이해하고 생각해내는 부분이 어려운 문제였던거 같다

- 시간복잡도 : O(N)