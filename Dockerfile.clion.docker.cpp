# Build and run:
#   docker build -t clion/ubuntu/cpp-env:1.0 -f Dockerfile.cpp-env-ubuntu .

FROM --platform=linux/amd64 ubuntu:18.04

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

RUN apt-get install -y sudo

ARG UID=1000
RUN adduser -u ${UID} --disabled-password --gecos '' dev \
    && echo 'dev ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers

USER dev
