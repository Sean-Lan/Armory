# Sliding Window

Define `[s1, e1]`, `[s2, e2]` as the optimal solutions under two windows ending with `e1` and `e2` respectivley. If `e1 < e2 => s1 <= s2`, problem can be solved with *sliding window* algorithm.

The basic structure of the solution to this kind of problem is:

    for (int s=0, e=0; e < n; ++e) {
      while (!isCandidateAnswer(s, e)) {
        ++ s;
      }
      updateAnswerWith(s, e);
    }

## Typical Problems

[Longest Substring with At Most Two Distinct Characters](./longestSubstringWithAtMostTwoDistinctCharacters.cpp)

[Longest Substring with At Most K Distinct Characters](./longestSubstringWithAtMostKDistinctCharacters.cpp)



