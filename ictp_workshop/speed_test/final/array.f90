program random_graph

 implicit none
 integer, parameter :: n = 5000
 integer :: A(n,n),i,j,k,num_sim
num_sim=200

 do k=1,num_sim
    do j = 1,n
        do i = 1,n
        A(i,j) = i+j
        enddo
    enddo
enddo

! do j=1,5
!    do  i= 1,5
      print *, A(1,1)
!    enddo
! enddo
end program
