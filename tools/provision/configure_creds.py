import argparse
import jinja2
import os

def _main():

    parser = argparse.ArgumentParser(
        description="Create aws_clientcredential_keys.h header file using the input credentials."
    )

    parser.add_argument(
        "--private-key",
        help="Path to the device private key PEM file.",
        type=str,
        default=None,
        required=True
    )

    parser.add_argument(
        "--certificate",
        help="Path to device certificate PEM file.",
        type=str,
        default=None,
        required=True
    )

    parser.add_argument(
        "--output",
        help="Path to output the credentials file.",
        type=str,
        default=None,
        required=True
    )

    args = parser.parse_args()

    cert = None
    with open(args.certificate) as cert_file:
        cert = cert_file.readlines()

    cert = [ x.strip() for x in cert]

    priv_key = None
    with open(args.private_key) as priv_key_file:
        priv_key = priv_key_file.readlines()

    priv_key = [ x.strip() for x in priv_key ]

    template = None
    template_path = os.path.join(os.path.dirname(__file__), "aws_clientcredential_keys.h.jinja2")
    with open(template_path) as template_file:
        template = jinja2.Template(template_file.read())
    
    keys_output = template.render(
        device_cert=cert,
        device_cert_len=len(cert),
        device_priv_key=priv_key,
        device_priv_key_len=len(priv_key))

    with open(args.output, "w") as outfile:
        outfile.write(keys_output)

if __name__ == "__main__":
    _main()
