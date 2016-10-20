cd ../ && make fclean && make
# cd .. && make re
echo " --> test with no param"
./fdf
echo "\n --> test with map empty"
./fdf test/empty_map.fdf
echo "\n --> test with not valid file"
./fdf Makefile
echo "\n --> test 4 x 4"
./fdf test/4_4.fdf & continue
sleep 1
pkill fdf
echo "\n --> test with 42.fdf map"
./fdf maps/42.fdf & continue
sleep 1
pkill fdf
echo "\n --> test with 10-2.fdf map"
./fdf maps/10-2.fdf & continue
sleep 1
pkill fdf
echo "\n --> test with 10-70.fdf map"
./fdf maps/10-70.fdf & continue
sleep 1
pkill fdf
echo "\n --> test with 20-60.fdf map"
./fdf maps/20-60.fdf & continue
sleep 1
pkill fdf
echo "\n --> test with 50-4.fdf map"
./fdf maps/50-4.fdf & continue
sleep 1
pkill fdf
echo "\n --> test with 100-6.fdf map"
./fdf maps/100-6.fdf & continue
sleep 1
pkill fdf
echo "\n --> test with basictest.fdf map"
./fdf maps/basictest.fdf & continue
sleep 1
pkill fdf
echo "\n --> test with elem-col.fdf map"
./fdf maps/elem-col.fdf & continue
sleep 1
pkill fdf
echo "\n --> test with elem-fract.fdf map"
./fdf maps/elem-fract.fdf & continue
sleep 2
pkill fdf
echo "\n --> test with elem.fdf map"
./fdf maps/elem.fdf & continue
sleep 1
pkill fdf
echo "\n --> test with elem2.fdf map"
./fdf maps/elem2.fdf & continue
sleep 1
pkill fdf
echo "\n --> test with france.fdf map"
./fdf maps/IGN_France_250_ASC_L93_OCEAN0_M.fdf & continue
sleep 2
pkill fdf
echo "\n --> test with julia.fdf map"
./fdf maps/julia.fdf & continue
sleep 2
pkill fdf
echo "\n --> test with mars.fdf map"
./fdf maps/mars.fdf & continue
sleep 1
pkill fdf
echo "\n --> test with pentenegpos.fdf map"
./fdf maps/pentenegpos.fdf & continue
sleep 1
pkill fdf
echo "\n --> test with plat.fdf map"
./fdf maps/plat.fdf & continue
sleep 1
pkill fdf
echo "\n --> test with pnp_flat.fdf map"
./fdf maps/pnp_flat.fdf & continue
sleep 1
pkill fdf
echo "\n --> test with pylone.fdf map"
./fdf maps/pylone.fdf & continue
sleep 1
pkill fdf
echo "\n --> test with pyra.fdf map"
./fdf maps/pyra.fdf & continue
sleep 1
pkill fdf
echo "\n --> test with pyramide.fdf map"
./fdf maps/pyramide.fdf & continue
sleep 1
pkill fdf
echo "\n --> test with t1.fdf map"
./fdf maps/t1.fdf & continue
sleep 1
pkill fdf
echo "\n --> test with t2.fdf map"
./fdf maps/t2.fdf & continue
sleep 1
pkill fdf


cd test/
