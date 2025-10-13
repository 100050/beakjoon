# [Platinum V] Rally - 30288 

[문제 링크](https://www.acmicpc.net/problem/30288) 

### 성능 요약

메모리: 2400 KB, 시간: 152 ms

### 분류

그래프 이론, 비둘기집 원리

### 제출 일자

2025년 10월 13일 23:12:11

### 문제 설명

<p>Byteland has N cities. Some of the cities are connected by roads.</p>

<p>Byteland rally organisers asked you to set up a track that would consist of exactly four roads and that would start and end in the same city. A road can not be added to the track more than once.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/0de5dcd6-238f-40db-926e-6900838226e7/-/preview/" style="width: 423px; height: 328px;"></p>

<p style="text-align: center;">Figure 1: Four marked roads make a valid track</p>

<p>Knowing the road map of Byteland, set up a rally track.</p>

### 입력 

 <p>The first line contains the number of cities N and the number of roads M. Cities are numbered from 1 to N.</p>

<p>The following M lines describe M roads. Each line contains 2 integers from 1 to N – the numbers of the cities the road connects.</p>

<p>Roads connect distinct cities, and any pair of cities is connected by at most one road.</p>

### 출력 

 <p>If it is possible to set up a track, output <code>TAIP</code> on the first line. On the second line output four numbers – the city numbers the track goes through.</p>

<p>If several solutions are possible, output any of them.</p>

<p>If it is impossible to set up a track, output <code>NE</code>.</p>

