# Ford-Fulkerson-algorithm

## 간단하게 먼저 알아야할 개념
* 유량 네트워크(flow network) : 간선에 용량이라는 속성이 있는 그래프이다.
* 용량(capacity) : 각 간선에 대해서 흐를 수 있는 최대 유량. c(u, v)
* 유량(flow) : 각 간선에 대해서 다음 constraints를 만족하는 값. f(u,v)




> 포드풀커슨 알고리즘에 대해 알아보기 전에 최대 유량 알고리즘(maximum flow algorithm)에 대해 먼저 알아야한다.
최대 유량 알고리즘(maximum flow algorithm)이란 Source(시작점)에서 Sink(도착점)으로 동시에 보낼 수 있는 데이터나 사물의 최대 양을 구하는 알고리즘이다. 이는 교통체증,커플매칭 등의 문제에 적합하다.



~~~
-> 다시 본론으로 돌아가서 그럼 포드풀커슨 알고리즘이 무엇이냐 최대 유량 알고리즘의 한 종류로 아래와 같은 동작과정을 통해 실행되는 알고리즘이다.
(s : 소스, t : 싱크)
1. 만약 s에서 t까지 모든 간선의 용량이 0보다 큰 경로 p를 구한다. 없으면 종료한다.
2. 그 경로의 용량의 최솟값 c를 구한다.
3. p에 포함된 모든 간선 (u, v)에 대해서 유량에 c를 더한다
4. 유량의 보존에 의해서 반대 간선인 (v, u)에는 유량에 c를 뺀다.
5. 1로 돌아간다.
(쉽게 말해 증가경로를 찾고 흘려보내는 것을 반복하는 것이다.)



~~~

* 그림과 함께 동작과정을 더 자세히 알아보자.

<p align="center"><img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FcWBbVy%2FbtqCU7ImoFe%2Fpc6Ku79lDJarwR7uON3S3k%2Fimg.png" height="200px" width="500px"></p>
 <br><br>
 > 각 간선에 표시된 값은 [유량 / 용량]이다. 이 그림은 매우 단순해서 우리는 s에서t까지의 최대유량이 2인 것을 안다.

<p align="center"><img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FQ5jD0%2FbtqCSYTanke%2F1fSjsLC25f4CLbCsN32Mlk%2Fimg.png" height="200px" width="500px"></p>
 <br><br>
 > 하지만 다음과 같이 경로를 찾았을 때 최대유량인 2가 도출되지 않았는데 더 이상 증가경로가 없는 것처럼 보인다.
 
<p align="center"><img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fb2gWWs%2FbtqCU7uJR9Z%2Fh6GwkjBZa31HlqhKag1M8K%2Fimg.png" height="200px" width="500px"></p>
 <br><br>
 > 그래서 포드풀커슨 알고리즘에서는 그림과 같이 역간선을 이용한다.
 
 <p align="center"><img src="https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FzyGxf%2FbtqCWdVy13O%2FhEGsKvZ0aEZnxMXKgkJ8PK%2Fimg.png" height="200px" width="500px"></p>
 <br><br>
 >b에서 a로 유량을 흘려보냈기 때문에 반대경로에는 유량을 빼줘야 한다.




~~~

이 과정에서 증가경로를 찾을때 DFS(깊이우선탐색)을 이용한 것이 바로 포드풀커슨 알고리즘이다.

~~~
* 포드-풀커슨 알고리즘의 시간복잡도는 최대 유량 f에 대해서 증가 경로를 찾기위해 많아도 탐색을 f번 하므로 O(V + E) F)이다. [V:정점 E:간선 F:유량]
## 코드실행결과
<p align="center"><img src="https://postfiles.pstatic.net/MjAyMjA0MjlfMTA0/MDAxNjUxMTg3ODU4NjI3.v4c8bGe6Xx88dN6zeCw8_yTYhXa9FEkICQ_DetmCNGMg.yyZ_o3W5EEiBMXATTVE7uJo4jWhoqmYrLiIE_aEKoZ0g.PNG.dyddyd4/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7(6).png?type=w773" height="400px" width="550px"></p>

---

> 번외로 포드-풀커슨 알고리즘은 아래와 같이 유량의 크기가 너무 커지면 과도하게 루프를 반복하게 된다.
<p align="center"><img src="https://gseok.gitbooks.io/algorithm/content/assets/networkflow-ford-fulkerson4.png" height="400px" width="550px"></p>

그래서 이와 같은 경우에 더 효울적으로 처리 할 수 있는 에드몬드 카프 알고리즘으로 보완 할 수 있다.
> 애드몬드 카프 알고리즘은 증가경로를 찾을 때 BFS(너비우선탐색)을 이용한 최대 유량 알고리즘이다.[시간복잡도:O(VE^2)]


> (그렇다고 에드몬드 카프 알고리즘이 포드-풀커슨 알고리즘보다 좋은 알고리즘인 것은 아니다. 에드몬드 카프 알고리즘은 E(간선)의 영향을 많이 받기 때문에 상황에 따라 유도리 있게 두 알고리즘을 잘 이용해야 한다.)

