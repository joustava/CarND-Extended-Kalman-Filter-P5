FROM archlinux

RUN pacman -Syyu --noconfirm
RUN pacman-db-upgrade
RUN pacman -S --noconfirm git libuv openssl gcc cmake make

# WORKDIR /deps

# RUN git clone --recursive https://github.com/uNetworking/uWebSockets.git
# RUN make -C uWebSockets
# RUN make install -C uWebSockets

WORKDIR /app
COPY . .

RUN cmake -S . -B build #-DEigen3_DIR=/app/extern/eigen/cmake/
RUN cmake --build build

CMD [ "./bin/KalmanExtended_LIB_TESTS" ]



