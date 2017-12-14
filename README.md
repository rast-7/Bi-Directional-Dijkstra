Bi-Directional Dijkstra
===================
Problem
--------------
Given a graph with non-negative edge weights, a source vertex **S** and a target vertec **T**. Find the shortest path between **S** and **T**

**But why don't we just use Dijkstra's Algorithm to solve the problem?**
> *0(E + VlogV)* is the worst case time complexity of the Dijkstra's Algorithm which is pretty fast. But, for a graph with 20million vertices and 50million edges, it will work for several seconds on average. So, we need something significantly faster.

**Before we go into the details of Bidirectional Search, let us explore the concept of *"Six Degrees of Separation"* **

> - In 1929, a Hungarian author, Frigyes Karinthy for the first time proposed the concept of *"Six Degrees of Separation"* in his short story Chains.
> - Six degrees of separation is the idea that all living things and everything else in the world are six or fewer steps away from each other.


Now, lets look at the most popular social network, Facebook. Suppose an average person on Facebook has around 100 friends. 
Then, if we consider friends of friends of that person, it will be 100*100 that is 10,000 friends of friends.
If we consider *"friends of friends of friends"* , that will be 100 times more or 1million.
And if we continue that six times we will have 1trillion people.

But, the global population is 7.6billion.

*Now, How do we find the shortest path between any two random persons A and B via their connections on the social network ?*
 
> Lets consider bidirectional search. So we will consider friends of friends of friends of A and friends of friends of friends of B. If the concept of Six Degrees of Separation is true, there will be a common person among friends of friends of friends of A and friends of friends of friends of B. Then we can easily find the shortest path that connects A and B.

Note that we will have roughly 1million friends of friends of friends for both A and B. So, in total we will consider only 2 million people in this case.

**Normal Dijkstra's Algorithm would have to look roughly  2billion people on the social network to find the shortest path between A and B.**

What is Bi-Directional Search
-----------------------------

In this, we run two simultaneous searches : one forward from initial state, and one backward from the goal, stopping when the two meet in the middle.

Pseudocode for Bi-Directional Dijkstra on the graph G
------------------------------------------------------

> - Build Gr(Reversed Graph)
> - Start Dijkstra from S(source) in G and from T(target) in Gr
> - Alternate between Dijkstra steps in G and in Gr
> - Stop when some vertex "v" is processed both in G and Gr.
> - Compute the shortest path between S and T.

> **Computation of the shortest path between S and T:**
Let dist[u] be the distance estimate in the forward Dijkstra from S in G.
Let distR[u] be the distance estimate in the backward Dijkstra from T in Gr.
After some node "v" is processed both in G and Gr, some shortest path from S to T passes through some node "u" which is processed either in G, in Gr or both and **d(S,T) = dist[u] + distR[u]**
