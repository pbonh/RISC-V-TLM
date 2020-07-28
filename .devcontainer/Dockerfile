FROM mariusmm/riscv-tlm

# Avoid warnings by switching to noninteractive
ENV DEBIAN_FRONTEND=noninteractive

ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# Configure apt and install packages
RUN apt-get update \
    && apt-get -y install build-essential cmake cppcheck valgrind; \
    apt-get install -y \
    apt-utils \
    ca-certificates \
    locales; \
    apt-get autoremove -y \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/*

RUN localedef -i en_US -f UTF-8 en_US.UTF-8 \
    && useradd -m -s /bin/bash $USERNAME \
    && echo '$USERNAME ALL=(ALL) NOPASSWD:ALL' >>/etc/sudoers

# Misc C++ Tools
RUN apt-get update -y
RUN apt-get install -y \
    gdb \
    ninja-build \
    libboost-all-dev \
    git

# Install Homebrew
RUN localedef -i en_US -f UTF-8 en_US.UTF-8 \
    && useradd -m -s /bin/bash linuxbrew \
    && echo 'linuxbrew ALL=(ALL) NOPASSWD:ALL' >>/etc/sudoers
ENV ORIGPATH=$PATH
USER linuxbrew
WORKDIR /home/linuxbrew
ENV PATH=/home/linuxbrew/.linuxbrew/bin:/home/linuxbrew/.linuxbrew/sbin:$PATH USER=linuxbrew
SHELL ["/bin/bash", "-o", "pipefail", "-c"]
RUN yes | /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)" &> homebrew.log && brew config; exit 0
RUN brew install python llvm navi fzf gcc@9 bear cmake; exit 0
RUN /home/linuxbrew/.linuxbrew/opt/fzf/install
ENV PATH=$ORIGPATH

USER root
#RUN localedef -i en_US -f UTF-8 en_US.UTF-8 \
#    && useradd -m -s /bin/bash $USERNAME \
#    && echo '$USERNAME ALL=(ALL) NOPASSWD:ALL' >>/etc/sudoers
RUN chown -R $USER_UID:$USER_GID /home/linuxbrew \
    && chown -R $USER_UID:$USER_GID /usr/src/riscv64
#RUN adduser $USERNAME $USERNAME
RUN mkdir /workspace
RUN mkdir /home/$USERNAME/workspace
RUN chown -R $USER_UID:$USER_GID /home/$USERNAME/workspace
RUN chown -R $USER_UID:$USER_GID /workspace

RUN update-alternatives --install /usr/bin/bear bear /home/linuxbrew/.linuxbrew/bin/bear 100

ENV LD_LIBRARY_PATH=/usr/local/systemc-2.3.3/lib-linux64

# Switch back to dialog for any ad-hoc use of apt-get
ENV DEBIAN_FRONTEND=dialog
