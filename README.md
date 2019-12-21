# Test_Task

1. Create an application which calculates prime numbers for intervals:
    - Load intervals from specified xml-based file;
    - For each interval start standalone thread for calculating prime numbers (threads calculations should be performed simultaneously);
    - Each calculation thread must store every calculated prime number to shared container (list, vector, etc);
    - Save unique prime numbers to xml-based file (primes tag).
2. Implement unit tests for the app using any unit test framework (GoogleMock, MS Test and etc.). Example of source xml file:

```XML
<root>
 <intervals>
   <interval>
     <low> 100 </low>
     <high> 200</high>
   </interval>
   <interval>
      <low> 500</low>
      <high> 888</high>
    </interval>
	....
  </intervals>
</root>
```

Example of output (may be added to the source xml file):
```XML
<root>
 <primes> 101 103 107 149 743  751… </primes>
</root>
```
