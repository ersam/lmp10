aprox: main.o splines.o points.o aproksymator_na_bazie.o gaus/libge.a
	$(CC) -o aprox  main.o splines.o points.o aproksymator_na_bazie.o -L gaus -l ge

intrp: main.o splines.o points.o interpolator.o gaus/libge.a
	$(CC) -o intrp  main.o splines.o points.o interpolator.o -L gaus -l ge

prosta: main.o splines.o points.o prosta.o
	$(CC) -o prosta  main.o splines.o points.o prosta.o

gsl_intrp: main.o splines.o points.o gsl_intrp.o gaus/libge.a
	$(CC) -o gsl_intrp main.o splines.o points.o gsl_intrp.o -lgsl -lgslcblas -lm -L gaus -l ge

gsl_approx: main.o splines.o points.o gsl_approx.o gaus/libge.a
	$(CC) -o gsl_approx main.o splines.o points.o gsl_approx.o -lgsl -lgslcblas -lm -Lgaus -l ge

aproksymator_na_bazie.o: makespl.h points.h gaus/piv_ge_solver.h
	$(CC) -I gaus -c aproksymator_na_bazie.c

interpolator.o: makespl.h points.h gaus/piv_ge_solver.h
	$(CC) -I gaus -c interpolator.c

gsl_intrp.o: makespl.h points.h gaus/piv_ge_solver.h
	$(CC) -I gaus -c gsl_intrp.c

gsl_approx.o: makespl.h points.h gaus/piv_ge_solver.h
	$(CC) -I gaus -c gsl_approx.c

.PHONY: clean

clean:
	-rm *.o aprox intrp prosta gsl_intrp gsl_approx
