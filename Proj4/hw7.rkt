#lang racket
( define course-list (cons '("Dept" "Number" "Section" "Class Nbr" "Capacity" "Enrollment")
                             '(("CMSC" "201" "1" "1052" 100 30)
                             ("CMSC" "341" "6" "7447" 40 27)
                             ("CMSC" "341" "3" "7443" "40" 29)
                             ("CMSC" "331" "5" "7746" 40 36)
                             ("CMSC" "331" "6" "7747" 40 "40")
                             ("CMSC" "471" "3" "8196" 40 31))
                             
                      )
)

#|
define a function as (open-seats section)
section is a member of course-list
in this function we calculate the available seats by deducting Enrollement from Capacity
and we prepare a string to be printed to the standard output in the following form:
CMSC341 (Section 6) => 13
|#

(define (open-seats section)

  #| String Creation, this is returned to report-open-seats |#
  
  (string-append
   (list-ref section 0) ; append CMSC
   (list-ref section 1) ; append course number
   " (Section "
   (list-ref section 2) ; append section number
   ") => "
   (number->string (- (list-ref section 4)(list-ref section 5))) ; Subtract enrollment from capacity and append
   "\n"
   )
  )


#|
define a function as (report-open-seats course-list)
In this function we iterate through course-list
for every course record we need to check whether both Enrollment and Capacity are numbers
If both are numbers then we call the function (open-seats ...) on the course record
if any of them is not a number we just ignore the record
and we print the returned string to the standard output
the result for every record should be printed on a new line
|#

(define (report-open-seats list-of-courses)
  
  (for ([i list-of-courses]) ; Iterate through list-of-courses (course-list), i is one of the inner lists  
    (if (and (number? (list-ref i 4)) (number? (list-ref i 5))) ; if element 4 and 5 of i are numbers  
        (display (open-seats i)) ; call open-seats, passing it i, and display what is returned
        (void) ; otherwise do nothing, skip the list
        ) 
    )
  )

; leave the following function call intact
(report-open-seats course-list)

#|

      THIS CODE HAS BEEN REWRITTEN AND REFACTORED ABOVE. I KEPT IT IN FOR PERSONAL REFERENCE

      I originally tried to code it as much like C++ as I could

    #| boolean variables for capacity and enrollment |#
    (define capacity #f)
    (define enrollment #f)

    #| Iterate through list-of-courses(course-list) |#
    (for ([i list-of-courses])
    
    #| Checks if capacity is a number |#
    (if (number? (list-ref i 4))
        (let ([capacity #t]) #t)
        (let ([capacity #f]) #f)
        )

    #| Checks if enrollment is a number |#
    (if (number? (list-ref i 5))
        (let ([enrollment #t]) #t)
        (let ([enrollment #f]) #f)
        )

    #| Calls open-seats if both capacity and enrollment are numbers
 sends open-seats the accepted list for calculation |#
    (if (and capacity enrollment)
        (display (open-seats i))
        (void)
        )
|#
