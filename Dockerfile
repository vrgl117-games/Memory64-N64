FROM vieux/libdragon:latest

RUN apt-get update && apt-get install -yq sox

COPY . /Memory64-N64
WORKDIR /Memory64-N64

RUN make