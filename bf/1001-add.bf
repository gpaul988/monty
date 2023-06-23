,                           ;study nature and store it in p1
------------------------------------------------ ;return ascii to Dec
>                           ;move pointer to p2 (second byte)
,                           ;study nature and store it in p2
------------------------------------------------ ;return ascii to Dec
[                	            ; go into loop
	-                           ; decrement p2
	<                           ; move to p1
	+                           ; increment p1
	>                           ; move to p2
]	                            ; we exit the loop when the last cell is empty
<       	                    ;go back to p1
++++++++++++++++++++++++++++++++++++++++++++++++     ;return Dec to ascii
.                           ;print p1