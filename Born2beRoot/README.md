*This project has been created as part of the 42 curriculum by cmarques.*

# Born2beRoot

## Description

Born2beRoot is a system-administration project whose goal is to configure a secure, minimal Linux server inside a virtual machine. It introduces virtualization, disk encryption, logical volume management, user and group administration, password policies, privilege control, firewalls, SSH, mandatory access control, scheduled tasks, logging, and basic system monitoring.

This implementation uses Debian 13 stable (Trixie) in Oracle VirtualBox. Debian was selected because it is stable, well documented, conservative in its package choices, and recommended by the subject for students who are new to system administration. No graphical server or desktop environment is installed.

### Main design choices

- Hypervisor: Oracle VirtualBox 7.0.
- Operating system: Debian 13 stable, installed from the amd64 netinst image.
- Virtual hardware: 2 GB RAM, 3 virtual CPUs, and a dynamically allocated 15 GiB virtual disk.
- Hostname: `cmarques42`.
- Main user: `cmarques`, belonging to the `user42` and `sudo` groups.
- Storage: an unencrypted `/boot` partition and an encrypted LUKS container containing LVM logical volumes for `/`, `/home`, and swap.
- Security: AppArmor, UFW, a strong password policy, and hardened `sudo` rules.
- Remote administration: OpenSSH on TCP port 4242, with direct root login disabled.
- Installed services: only the minimal services required for the mandatory project; no graphical environment or bonus web stack is installed.
- Monitoring: `/usr/local/bin/monitoring.sh`, executed by root through cron at startup and every 10 minutes.

### Technical comparisons

#### Debian vs Rocky Linux

Debian is a community-driven distribution known for stability, a large package repository, the `apt` package-management ecosystem, and extensive documentation. It is a good choice for a small first server because its minimal installation is straightforward and predictable. Its conservative package versions may be older than those in faster-moving distributions.

Rocky Linux is an enterprise-oriented distribution compatible with the Red Hat Enterprise Linux ecosystem. It uses RPM packages with `dnf`, SELinux, and firewalld. It is useful for learning technologies commonly found in Red Hat-based enterprise environments, but its security and installation workflow can be more complex for a beginner.

#### AppArmor vs SELinux

Both provide mandatory access control beyond normal Unix permissions.

AppArmor restricts applications using profiles based primarily on filesystem paths. It is generally easier to read and configure and is enabled by default on Debian.

SELinux applies labels to processes and resources and enforces policies using those security contexts. It provides very detailed and powerful controls, but its policy model has a steeper learning curve. Rocky Linux uses SELinux.

#### UFW vs firewalld

UFW is a simple interface for managing Linux firewall rules. Its concise commands make it suitable for a small Debian server. This VM permits only incoming TCP traffic on port 4242.

firewalld is a dynamic firewall manager commonly used by Rocky Linux. It supports zones and runtime/permanent rule sets, making it convenient for machines that move between different network trust levels. It is more feature-rich but unnecessary for this minimal Debian setup.

#### VirtualBox vs UTM

VirtualBox is a cross-platform type-2 hypervisor widely used on Intel and AMD computers. It offers a graphical manager, virtual disks, NAT networking, and port forwarding.

UTM is especially useful on Apple Silicon and is built around QEMU and Apple virtualization technologies. It supports both virtualization and emulation, but the latter can be slower when the guest architecture differs from the host. VirtualBox was selected because it is available on the 42 computer used for this project.

## Instructions

The virtual machine itself is not stored in this Git repository. It is stored locally in the user's `goinfre` directory and must be opened with Oracle VirtualBox.

To use the server:

1. Start the `Born2beRoot` VM in VirtualBox.
2. Enter the LUKS disk-encryption passphrase when requested.
3. Log in locally as `cmarques`, or connect through SSH.

The SSH server listens on port 4242 inside the VM:

```bash
ssh -p 4242 cmarques@<vm-ip-address>
```

With the local VirtualBox NAT rule used during development, host port 4243 forwards to guest port 4242:

```bash
ssh -p 4243 cmarques@127.0.0.1
```

The firewall and principal services can be inspected with:

```bash
sudo ufw status numbered
sudo systemctl status ssh --no-pager
sudo systemctl status apparmor --no-pager
sudo systemctl status cron --no-pager
```

The monitoring script can be tested manually with:

```bash
sudo /usr/local/bin/monitoring.sh
```

Its schedule can be inspected with:

```bash
sudo crontab -l
```

Cron can be interrupted without modifying the script:

```bash
sudo systemctl stop cron
```

It can be started again with:

```bash
sudo systemctl start cron
```

Before submission, shut down the VM cleanly and calculate the SHA-1 digest of its `.vdi` file on the host computer:

```bash
sha1sum Born2beRoot.vdi
```

Only the resulting digest belongs in `signature.txt`. Starting the VM again changes the virtual disk and therefore requires generating a new signature. The `.vdi` file must never be committed to Git, and each evaluation must begin without snapshots.

## Security configuration overview

### Password policy

- Passwords expire after 30 days.
- At least 2 days must pass between password changes.
- Users are warned 7 days before expiry.
- Passwords contain at least 10 characters, including uppercase and lowercase letters and a number.
- More than 3 consecutive identical characters are rejected.
- Passwords containing the username are rejected.
- Non-root password changes require at least 7 characters not present in the previous password.
- The applicable quality rules are also enforced for root.

### Sudo policy

- Authentication is limited to 3 attempts.
- A custom message is displayed after an incorrect password.
- TTY mode is required.
- A restricted secure path is used.
- Commands and their input/output are logged under `/var/log/sudo/`.

### Network policy

- OpenSSH listens on TCP port 4242.
- Direct SSH login as root is disabled.
- UFW starts automatically and permits only TCP port 4242 for the mandatory configuration.

## Resources

- Born2beRoot subject, version 5.2 — project requirements supplied through the 42 intranet.
- [Debian installation guide](https://www.debian.org/releases/stable/amd64/) — Debian installation and platform documentation.
- [Debian Administrator's Handbook](https://www.debian.org/doc/manuals/debian-handbook/) — package management, services, users, security, and system administration.
- [OpenSSH manual pages](https://manpages.debian.org/stable/openssh-server/sshd_config.5.en.html) — SSH server configuration options.
- [AppArmor documentation](https://apparmor.net/) — mandatory access-control concepts and profiles.
- [UFW manual page](https://manpages.debian.org/stable/ufw/ufw.8.en.html) — firewall commands and rule management.
- Local manual pages such as `man sudoers`, `man sshd_config`, `man ufw`, `man crontab`, `man wall`, `man chage`, and `man lsblk`.

### Use of AI

AI was used as an interactive learning assistant during this project. It helped break the installation into small steps, explain Linux and virtualization concepts, classify choices as subject requirements or implementation decisions, interpret command output, diagnose SSH/NAT and terminal-message behaviour, and review the configuration against the subject. It was also used to prepare the initial structure and wording of this README.

All commands were executed and checked manually by the student on the virtual machine. Passwords and encryption passphrases were never shared with the AI. The final configuration, command behaviour, monitoring script, and technical decisions must be understood and defended by the student.
