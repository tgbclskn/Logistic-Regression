# Logistic Regression in C <img src="http://www.pngpix.com/wp-content/uploads/2016/11/PNGPIX-COM-Pie-Chart-PNG-Transparent-Image-500x498.png" width="100" height="100" align="right"/> 
[![Open Source Love](https://badges.frapsoft.com/os/v2/open-source.svg?v=103)](https://github.com/ellerbrock/open-source-badges/) [![GPL Licence](https://badges.frapsoft.com/os/gpl/gpl.svg?v=103)](https://opensource.org/licenses/GPL-3.0/) [![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](https://GitHub.com/Naereen/StrapDown.js/graphs/commit-activity)

### Building and Running
``` bash
    cmake -Bbuild -H.
    cmake --bulid build --traget all
    ./build/LogisticRegression
```

### Expected Output

```
loading data from ../dataset/Iris.csv...
number of training examples... ( 100 )
shuffling the dataset...
splitting the train/test with the ratio... < 0.8 | 0.2 >
calculating train set length... ( 80 )
calculating test set length... ( 20 )

================ Logistic Regression ===============
    - learning rate           : 0.050000
    - number of iterations    : 20

  [   0 ] training model... cost ---> | 0.693147 |
  [   1 ] training model... cost ---> | 0.658378 |
  [   2 ] training model... cost ---> | 0.626176 |
  [   3 ] training model... cost ---> | 0.596341 |
  [   4 ] training model... cost ---> | 0.568686 |
  [   5 ] training model... cost ---> | 0.543033 |
  [   6 ] training model... cost ---> | 0.519217 |
  [   7 ] training model... cost ---> | 0.497084 |
  [   8 ] training model... cost ---> | 0.476493 |
  [   9 ] training model... cost ---> | 0.457314 |
  [  10 ] training model... cost ---> | 0.439429 |
  [  11 ] training model... cost ---> | 0.422729 |
  [  12 ] training model... cost ---> | 0.407116 |
  [  13 ] training model... cost ---> | 0.392500 |
  [  14 ] training model... cost ---> | 0.378799 |
  [  15 ] training model... cost ---> | 0.365939 |
  [  16 ] training model... cost ---> | 0.353853 |
  [  17 ] training model... cost ---> | 0.342480 |
  [  18 ] training model... cost ---> | 0.331764 |
  [  19 ] training model... cost ---> | 0.321655 |

================= Training Complete ================
final weights and biases...

    |    0.25 |
    |   -0.25 |
    |    0.35 |
    |    0.35 |


    |    0.01 |

making predictions on the test set...
calculating the model accuracy...
    =================================
    || Accuracy     ||    1.000000 ||
    =================================
```

## License
[![licensebuttons by-nc-sa](https://licensebuttons.net/l/by-nc-sa/3.0/88x31.png)](https://creativecommons.org/licenses/by-nc-sa/4.0)

This work is licensed under [GNU General Public License v3.0](https://github.com/atick-faisal/PIC16F877a/blob/master/LICENSE).
