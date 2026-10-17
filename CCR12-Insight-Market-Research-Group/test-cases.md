# Test Cases - CCR12 Insight Market Research Group

## Acceptance Criteria

```
student@9b36e72c8c17:/workspace/c/CCR12-Insight-Market-Research-Group$ ./CCR12-Insight
Number of Survey Scores: 5
Score 1: 85
Score 2: 92
Score 3: 78
Score 4: 96
Score 5: 89

----------------------------------------------
Insight Market Research Group
Survey Summary Report
----------------------------------------------
Survey Responses: 5
Highest Score: 96
Lowest Score: 78
Average Score: 88.0
----------------------------------------------
Memory released successfully
program completed.
----------------------------------------------
```

## Test Cases

### Invalid Input Tests

#### 1. Empty Input (User presses Enter without typing anything)
- **Input**: (empty)
- **Expected Output**: `Invalid input. Please enter a positive integer for the number of scores:`

#### 2. Zero as Number of Scores
- **Input**: `Number of Survey Scores: 0`
- **Expected Output**: `Invalid input. Please enter a positive integer for the number of scores:`

#### 3. More than 10 Survey Scores
- **Input**: `Number of Survey Scores: 11`
- **Expected Output**: `Invalid input. Maximum number of survey scores is 10:`

#### 4. Score Greater than 100
- **Input**: `Score 1: 101`
- **Expected Output**: `Invalid input. Enter a number between 0 and 100:`

#### 5. Negative Score
- **Input**: `-98`
- **Expected Output**: `Invalid input. Enter a number between 0 and 100:`

#### 6. Non-Numeric Input (Characters)
- **Input**: `Score 1: A`
- **Expected Output**: `Invalid input. Enter a number between 0 and 100:`
