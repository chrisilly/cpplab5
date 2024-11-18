**Chris Culling**

Lab for **assignment 5**

13 Nov 2024

---

### Insights

In order to implement a `friend` method declared in a class in a header file, you need to drop the class prefix, because it's apparently not a member of the class. Maybe it just gives the class exclusive access to it?

Y'all have written some functions with lower-case beginnings i.e. `push_back()` or `shrink_to_fit()` but some with capital letters i.e. `Invariant()`. This confuses me; what are the naming conventions??? What should I stick to?? 😵

Really wish someone had told me about `std::memcpy()` for this assignment.