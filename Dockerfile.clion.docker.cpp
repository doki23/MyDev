# Build and run:
#   docker build -t clion/ubuntu/cpp-env:1.0 -f Dockerfile.cpp-env-ubuntu .

FROM ubuntu:22.04

RUN DEBIAN_FRONTEND="noninteractive" apt-get update && apt-get -y install tzdata

RUN apt-get update \
  && apt-get install -y build-essential \
      gcc \
      g++ \
      gdb \
      clang \
      make \
      ninja-build \
      cmake \
      autoconf \
      automake \
      ccache \
      locales-all \
      dos2unix \
      rsync \
      tar \
      python2.7 \
      git \
  && apt-get clean

ARG UID=1000
RUN useradd -m -u ${UID} -s /bin/bash dev
USER dev
