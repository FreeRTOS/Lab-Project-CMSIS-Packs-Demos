#ifndef AWS_CLIENT_CREDENTIAL_KEYS_H
#define AWS_CLIENT_CREDENTIAL_KEYS_H

#include <stdint.h>

/*
 * PEM-encoded client certificate.
 *
 * Must include the PEM header and footer:
 * "-----BEGIN CERTIFICATE-----\n"\
 * "...base64 data...\n"\
 * "-----END CERTIFICATE-----"
 */
#define keyCLIENT_CERTIFICATE_PEM \
"-----BEGIN CERTIFICATE-----\n"\
"MIIDWjCCAkKgAwIBAgIVAM/LgzcTyuUVBsblZO4D73zMFF59MA0GCSqGSIb3DQEB\n"\
"CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t\n"\
"IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0xOTA5MjUyMzMx\n"\
"MjhaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh\n"\
"dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQCyRn9szd2f1SOiEDUc\n"\
"WqW8XqKUNS8+7NKEG4vNMgXKhPXFcS9LRb0EOg1c/71kbNdV5Ykgr87YxhvnsGbS\n"\
"d7YlYO/Vc5hJrqgD179uE0hicwLcNx+ViCz3TKdNggxy48oQhAkivfP2S/JQseAN\n"\
"7rG2mAOmrCK4Bq0SKgfLN+L0x9xVvSEehWYlwX1ZcSvr9LxxCawRkHCVliIwn4Ir\n"\
"V75ln+7gdRQw3qcPkGXedkjJWG0lJR0g9ne4pqL3cN28Pps0vUnJGx/nz5Fepo+/\n"\
"cd+5EffZFoVqvwSmTgwEQBszfnaN8QwfvVCZoMXY+t9i0s3X+7E9zL+UhdMgJizq\n"\
"4saFAgMBAAGjYDBeMB8GA1UdIwQYMBaAFGFroVJbKcRdiKtpOptCdefvAZ22MB0G\n"\
"A1UdDgQWBBQ23M5+IBpEPN2bbO0XqbpU4FzU0TAMBgNVHRMBAf8EAjAAMA4GA1Ud\n"\
"DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEALokHN991GFzNLy/+iOdetl/K\n"\
"2C3z2/IQVTsDJqoUJrwo9TSeyqAAWP+FVsz5Pd4yixYWtPPFCwKH1zIPXjUa+Zch\n"\
"OVqolGQUiLesA3iEAgbNGDlEaHHYyfP3lW0UvvDQ3wmq90hehNmjI+//y7o/vEsu\n"\
"WG8InbRzIrzdwN1pvXzYPL3Rt0DsNe7Qmn1sOLrZFHvvIJVGfAaM4SfbAuCmJhri\n"\
"xjTO8EXdxrHdiSjcyujlYllthcoR/zd/jD4uYDsi+YhxHE15DVFgTk8hifF7fSyS\n"\
"/ByIyKULlBvEMnyL2gkmvz6lQZFhQ2+uCZbhTx4kmM3rReZfDUpR1XRP9PoFdQ==\n"\
"-----END CERTIFICATE-----"
   /*
 * PEM-encoded client private key.
 *
 * Must include the PEM header and footer:
 * "-----BEGIN RSA PRIVATE KEY-----\n"\
 * "...base64 data...\n"\
 * "-----END RSA PRIVATE KEY-----"
 */
#define keyCLIENT_PRIVATE_KEY_PEM \
"-----BEGIN RSA PRIVATE KEY-----\n"\
"MIIEpQIBAAKCAQEAskZ/bM3dn9UjohA1HFqlvF6ilDUvPuzShBuLzTIFyoT1xXEv\n"\
"S0W9BDoNXP+9ZGzXVeWJIK/O2MYb57Bm0ne2JWDv1XOYSa6oA9e/bhNIYnMC3Dcf\n"\
"lYgs90ynTYIMcuPKEIQJIr3z9kvyULHgDe6xtpgDpqwiuAatEioHyzfi9MfcVb0h\n"\
"HoVmJcF9WXEr6/S8cQmsEZBwlZYiMJ+CK1e+ZZ/u4HUUMN6nD5Bl3nZIyVhtJSUd\n"\
"IPZ3uKai93DdvD6bNL1JyRsf58+RXqaPv3HfuRH32RaFar8Epk4MBEAbM352jfEM\n"\
"H71QmaDF2PrfYtLN1/uxPcy/lIXTICYs6uLGhQIDAQABAoIBAQCp9EdaZNAZpcn4\n"\
"oFbhlxFViSqY/DL0XDU9OD2I+11F+oeLGSIrMmrF8sn2lN/rM0/+VXrrLG+XfRXx\n"\
"RNxhXTrKW6WI6lCOPfFy6GVY/Q0OvfJGGk8D8PRdNjhwzcAsbzidkiJbepdvgGub\n"\
"vleJMLs/BaDFbmkS41pvbJ5NgBPfomfR9LqIpDpHom5zsDRD4kJGjgznRVK0M2VH\n"\
"/uiCvOe656UDI3I7wJ0YVXbicqj8U5GFFwnDrEcG5paXosOb1tAyXOZVreHbv4DI\n"\
"AnflxnFikSUEbyOQutOH5WXLfqMbJp1pgvdypu2a9fIgbPFx/ILeja/gXNjnBJr6\n"\
"PPpQ1kvBAoGBAOzEslOVlE+N7pqbkTFaN2n94D/zGUMuYd4lqwzpSSY7Lv1KVmBF\n"\
"col/9Lji6LsCHHh3AhLS6J36xzetB7fh5GYhK+l++31tETEF+VtEhrJo9JyWQT9+\n"\
"/M0g0sZEhJ19AcGjEHmpSd1B+IXYimaDUjnhgmBYEUE7fWfC6WovwZZNAoGBAMDB\n"\
"gz/Qr1IOQvNNlf7c8RzzR3/x+X4Vb2kPw7iSgBmOO5yaLK17Ui7yVnkeGKPE7/ca\n"\
"a/q7UPrtF94XhexWuXK4w5mHR/au9LTOC/quPehl5P5oFAV3/OhW5/ywGlxcS532\n"\
"jasySM2mhtGQ4MRmyJlspmkjPYANiRImt4rXtf0ZAoGBAJyMIWxqhjljmtPW8FU1\n"\
"VVZbah5eWeG1lTgQp9xNkvQYRaVrtVjKEkUfuWtVfJPJfZGY/mH72Zo66eXCHkxS\n"\
"q3VrkWE9eIMhzjAfxxO1Z2onQzUVk+ary/LFNReqzhRjRvoFGyuV5yTILc4xsrC9\n"\
"O2zR0iZplF8ROoWUtkhjcxgxAoGAJsbHII9ataco0MlK43qPBsPqHlMPXc3yG7CQ\n"\
"LxFJs9ppI5fgZQXqAoe93Z+wVUHJBGzMTCRiphgMNSGGT4UiyXFh6ADO+VE46SaK\n"\
"QmPLEHVvG77USEVbG2JgSPUkWHA4xg5TcZ0sCDL37DC5BsmmkTbKQ1xTgu82I/Cl\n"\
"+8hpVAECgYEA4i6XOSgF1ySGLRFM+TzS9B+FcFzFXOxdEdE44YwQC7l204Xi/uyo\n"\
"FFfVWovYYw/Ztedu4T/z/E9FAzthr48IfZ675Zd+Qfvjb87Zg5ORxkQjV554z70I\n"\
"6LJu8/7VEnWp7dIg/0eoalyOc8r9g3I19+Rr+Wzsme/t2MByLLQYKPQ=\n"\
"-----END RSA PRIVATE KEY-----"
   /*
 * PEM-encoded Just-in-Time Registration (JITR) certificate (optional).
 *
 * If used, must include the PEM header and footer:
 * "-----BEGIN CERTIFICATE-----\n"\
 * "...base64 data...\n"\
 * "-----END CERTIFICATE-----"
 */
#define keyJITR_DEVICE_CERTIFICATE_AUTHORITY_PEM  ""


#endif /* AWS_CLIENT_CREDENTIAL_KEYS_H */