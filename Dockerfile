FROM vieux/libdragon:latest

COPY . /Memory64-N64
WORKDIR /Memory64-N64

RUN make