/*
	commit id : d3ab93e9c372c98c4ee3bcf8bc3c406a19e62f95
*/

#include <stdio.h>
#include <stdlib.h>

#include "../stdio.h"
#include "../openssl.h"

# define EVP_MAX_MD_SIZE                 64/* longest known is SHA512 */
# define EVP_MAX_KEY_LENGTH              64
# define EVP_MAX_IV_LENGTH               16
# define EVP_MAX_BLOCK_LENGTH            32

# define PKCS5_SALT_LEN                  8
/* Default PKCS#5 iteration count */
# define PKCS5_DEFAULT_ITER              2048


typedef struct {} RECORD_LAYER;

struct ssl_st {
    /*
     * The TLS1.3 early_secret and handshake_secret. The master_secret is stored
     * in the session.
     */
    EVP_CIPHER_CTX *enc_read_ctx; /* cryptographic state */
    unsigned char read_iv[EVP_MAX_IV_LENGTH]; /* TLSv1.3 static read IV */
    EVP_MD_CTX *read_hash;      /* used for mac generation */
    COMP_CTX *compress;         /* compression */
    COMP_CTX *expand;           /* uncompress */
    EVP_CIPHER_CTX *enc_write_ctx; /* cryptographic state */
    unsigned char write_iv[EVP_MAX_IV_LENGTH]; /* TLSv1.3 static write IV */
    EVP_MD_CTX *write_hash;     /* used for mac generation */
    /* session info */
    /* client cert? */
    /* This is used to hold the server certificate used */
    struct cert_st /* CERT */ *cert;
    /*
     * Callback for disabling session caching and ticket support on a session
     * basis, depending on the chosen cipher.
     */
    RECORD_LAYER rlayer;
};

struct record_data {
    const char *plaintext;
    const char *ciphertext;
    const char *key;
    const char *iv;
    const char *seq;
} refdata[] = {
    {
        "0800001e001c000a00140012001d0017001800190100010101020103010400000000"
        "0b0001b9000001b50001b0308201ac30820115a003020102020102300d06092a8648"
        "86f70d01010b0500300e310c300a06035504031303727361301e170d313630373330"
        "3031323335395a170d3236303733303031323335395a300e310c300a060355040313"
        "0372736130819f300d06092a864886f70d010101050003818d0030818902818100b4"
        "bb498f8279303d980836399b36c6988c0c68de55e1bdb826d3901a2461eafd2de49a"
        "91d015abbc9a95137ace6c1af19eaa6af98c7ced43120998e187a80ee0ccb0524b1b"
        "018c3e0b63264d449a6d38e22a5fda430846748030530ef0461c8ca9d9efbfae8ea6"
        "d1d03e2bd193eff0ab9a8002c47428a6d35a8d88d79f7f1e3f0203010001a31a3018"
        "30090603551d1304023000300b0603551d0f0404030205a0300d06092a864886f70d"
        "01010b05000381810085aad2a0e5b9276b908c65f73a7267170618a54c5f8a7b337d"
        "2df7a594365417f2eae8f8a58c8f8172f9319cf36b7fd6c55b80f21a030151567260"
        "96fd335e5e67f2dbf102702e608ccae6bec1fc63a42a99be5c3eb7107c3c54e9b9eb"
        "2bd5203b1c3b84e0a8b2f759409ba3eac9d91d402dcc0cc8f8961229ac9187b42b4d"
        "e100000f00008408040080134e22eac57321ab47db6b38b2992cec2dd79bd065a034"
        "a9af6b9e3d03475e4309e6523ccdf055453fb480804a3a7e996229eb28e734f6702b"
        "ea2b32149899ac043a4b44468197868da77147ce9f73c0543c4e3fc33e306cac8506"
        "faa80a959c5f1edccbee76eda1ad7a4fa440de35dcb87e82ec94e8725355ce750771"
        "3a609e140000207304bb73321f01b71dd94622fae98daf634490d220e4c8f3ffa255"
        "9911a56e5116",
        "40ae92071a3a548b26af31e116dfc0ba4549210b17e70da16cfbda9ccdad844d9426"
        "4a9ae65b786b3eaf0de20aa89c6babb448b6f32d07f233584296eefe19316bd97965"
        "9472ee8567cb01d70b0366cddb3c60eb9e1d789a3691dc254c14de73f4f201005045"
        "44ce184d44547e124b1f18303b4859f8f2e2b04423d23a866b43866374d54af41649"
        "d25f4a3ec2cecd5d4e6de1b24953440b46fbb74c1dbec6fbb1f16bc21d4aa0e1e936"
        "a49c07127e19719bc652a2f0b7f8df4a150b2b3c9e9e353d6ed101970ddc611abad0"
        "632c6793f9379c9d06846c311fcbd6f85edd569b8782c4c5f62294c4611ae60f8323"
        "0a53aa95e3bcbed204f19a7a1db83c0fbfec1edd2c17498fa7b5aa2321248a92592d"
        "891e4947df6bcef52f4481797d032ad332046a384abece6454b3e356d7249bfa5696"
        "793c7f7d3048dc87fa7409a4691887caaf0982c402b902d699f62dc4d5e153f13e85"
        "89e4a6206c7f74eb26ddefbb92309fb753decfea972dec7de02eda9c6d26acd7be53"
        "a8aa20f1a93f082ae6eb927a6a1b7bd9153551aedfaf94f61dd4cb9355ad7ab09f61"
        "5d9f92c21712c732c0e7e117797f38cbdc184e3a65e15a89f46cb3624f5fdb8dbbd2"
        "75f2c8492f8d95bdbd8d1dc1b9f21107bd433acbbac247239c073a2f24a4a9f8074f"
        "325f277d579b6bff0269ff19aed3809a9ddd21dd29c1363c9dc44812dd41d2111f9c"
        "2e8342046c14133b853262676f15e94de18660e04ae5c0c661ea43559af5842e161c"
        "83dd29f64508b2ec3e635a2134fc0e1a39d3ecb51dcddfcf8382c88ffe2a737842ad"
        "1de7fe505b6c4d1673870f6fc2a0f2f7972acaee368a1599d64ba18798f10333f977"
        "9bd5b05f9b084d03dab2f3d80c2eb74ec70c9866ea31c18b491cd597aae3e941205f"
        "cc38a3a10ce8c0269f02ccc9c51278e25f1a0f0731a9",
        "d2dd45f87ad87801a85ac38187f9023b",
        "f0a14f808692cef87a3daf70",
        "0000000000000000"
    },
    {
        "1400002078367856d3c8cc4e0a95eb98906ca7a48bd3cc7029f48bd4ae0dc91ab903"
        "ca8916",
        "fa15e92daa21cd05d8f9c3152a61748d9aaf049da559718e583f95aacecad657b52a"
        "6562da09a5819e864d86ac2989360a1eb22795",
        "40e1201d75d419627f04c88530a15c9d",
        "a0f073f3b35e18f96969696b",
        "0000000000000000"
    },
    {
        "040000a60002a3004abe594b00924e535321cadc96238da09caf9b02fecafdd65e3e"
        "418f03e43772cf512ed8066100503b1c08abbbf298a9d138ce821dd12fe1710e2137"
        "cd12e6a85cd3fd7f73706e7f5dddefb87c1ef83824638464099c9d1363e3c64ed207"
        "5c16b8ccd8e524a6bbd7a6a6e34ea1579782b15bbe7dfed5c0c0d980fb330f9d8ab2"
        "52ffe7be1277d418b6828ead4dae3b30d448442417ef76af0008002e000400020000"
        "16",
        "45a6626fa13b66ce2c5b3ef807e299a118296f26a2dd9ec7487a0673e2460d4c79f4"
        "0087dcd014c59c51379c90d26b4e4f9bb2b78f5b6761594f013ff3e4c78d83690522"
        "9eac811c4ef8b2faa89867e9ffc586f7f03c216591aa5e620eac3c62dfe60f846036"
        "bd7ecc4464b584af184e9644e94ee1d7834dba408a51cbe4248004796ed9c558e0f5"
        "f96115a6f6ba487e17d16a2e20a3d3a650a9a070fb53d9da82864b5621d77650bd0c"
        "7947e9889917b53d0515627c72b0ded521",
        "3381f6b3f94500f16226de440193e858",
        "4f1d73cc1d465eb30021c41f",
        "0000000000000000"
    },
    {
        "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f2021"
        "22232425262728292a2b2c2d2e2f303117",
        "e306178ad97f74bb64f35eaf3c39846b83aef8472cbc9046749b81a949dfb12cfbc6"
        "5cbabd20ade92c1f944605892ceeb12fdee8a927bce77c83036ac5a794a8f54a69",
        "eb23a804904b80ba4fe8399e09b1ce42",
        "efa8c50c06b9c9b8c483e174",
        "0000000000000000"
    },
    {
        "000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20212"
        "2232425262728292a2b2c2d2e2f303117",
        "467d99a807dbf778e6ffd8be52456c70665f890811ef2f3c495d5bbe983feedab0c25"
        "1dde596bc7e2b135909ec9f9166fb0152e8c16a84e4b1039256467f9538be4463",
        "3381f6b3f94500f16226de440193e858",
        "4f1d73cc1d465eb30021c41f",
        "0000000000000001"
    },
    {
        "010015",
        "6bdf60847ba6fb650da36e872adc684a4af2e8",
        "eb23a804904b80ba4fe8399e09b1ce42",
        "efa8c50c06b9c9b8c483e174",
        "0000000000000001"
    },
    {
        "010015",
        "621b7cc1962cd8a70109fee68a52efedf87d2e",
        "3381f6b3f94500f16226de440193e858",
        "4f1d73cc1d465eb30021c41f",
        "0000000000000002"
    }
};

/* Padding modes */
#define EVP_PADDING_PKCS7       1
#define EVP_PADDING_ISO7816_4   2
#define EVP_PADDING_ANSI923     3
#define EVP_PADDING_ISO10126    4
#define EVP_PADDING_ZERO        5

/* RFC 5246 defines additional data to be 13 bytes in length */
# define         EVP_AEAD_TLS1_AAD_LEN           13

typedef struct {
	unsigned char *out;
	const unsigned char *inp;
	size_t len;
	unsigned int interleave;
} EVP_CTRL_TLS1_1_MULTIBLOCK_PARAM;

/* GCM TLS constants */
/* Length of fixed part of IV derived from PRF */
# define EVP_GCM_TLS_FIXED_IV_LEN                        4
/* Length of explicit part of IV part of TLS records */
# define EVP_GCM_TLS_EXPLICIT_IV_LEN                     8
/* Length of tag for TLS */
# define EVP_GCM_TLS_TAG_LEN                             16

/* CCM TLS constants */
/* Length of fixed part of IV derived from PRF */
# define EVP_CCM_TLS_FIXED_IV_LEN                        4
/* Length of explicit part of IV part of TLS records */
# define EVP_CCM_TLS_EXPLICIT_IV_LEN                     8


/* Function codes. */
# define CRYPTO_F_CRYPTO_DUP_EX_DATA                      110
# define CRYPTO_F_CRYPTO_FREE_EX_DATA                     111
# define CRYPTO_F_CRYPTO_GET_EX_NEW_INDEX                 100
# define CRYPTO_F_CRYPTO_MEMDUP                           115
# define CRYPTO_F_CRYPTO_NEW_EX_DATA                      112
# define CRYPTO_F_CRYPTO_SET_EX_DATA                      102
# define CRYPTO_F_FIPS_MODE_SET                           109
# define CRYPTO_F_GET_AND_LOCK                            113
# define CRYPTO_F_OPENSSL_BUF2HEXSTR                      117
# define CRYPTO_F_OPENSSL_HEXSTR2BUF                      118
# define CRYPTO_F_OPENSSL_INIT_CRYPTO                     116

/* Reason codes. */
# define CRYPTO_R_FIPS_MODE_NOT_SUPPORTED                 101
# define CRYPTO_R_ILLEGAL_HEX_DIGIT                       102
# define CRYPTO_R_ODD_NUMBER_OF_DIGITS                    103



typedef struct ssl3_buffer_st {
    /* at least SSL3_RT_MAX_PACKET_SIZE bytes, see ssl3_setup_buffers() */
    unsigned char *buf;
    /* default buffer size (or 0 if no default set) */
    size_t default_len;
    /* buffer size */
    size_t len;
    /* where to 'copy from' */
    size_t offset;
    /* how many bytes left */
    size_t left;
} SSL3_BUFFER;

#define SEQ_NUM_SIZE                            8

typedef struct ssl3_record_st {
    /* Record layer version */
    /* r */
    int rec_version;
    /* type of record */
    /* r */
    int type;
    /* How many bytes available */
    /* rw */
    size_t length;
    /*
     * How many bytes were available before padding was removed? This is used
     * to implement the MAC check in constant time for CBC records.
     */
    /* rw */
    size_t orig_len;
    /* read/write offset into 'buf' */
    /* r */
    size_t off;
    /* pointer to the record data */
    /* rw */
    unsigned char *data;
    /* where the decode bytes are */
    /* rw */
    unsigned char *input;
    /* only used with decompression - malloc()ed */
    /* r */
    unsigned char *comp;
    /* Whether the data from this record has already been read or not */
    /* r */
    unsigned int read;
    /* epoch number, needed by DTLS1 */
    /* r */
    unsigned long epoch;
    /* sequence number, needed by DTLS1 */
    /* r */
    unsigned char seq_num[SEQ_NUM_SIZE];
} SSL3_RECORD;

static int load_record(SSL3_RECORD *rec, size_t recnum, unsigned char **key,
                       unsigned char *iv, size_t ivlen, unsigned char *seq)
{
    unsigned char *pt = NULL, *sq = NULL, *ivtmp = NULL;;
    long ptlen;

    *key = OPENSSL_hexstr2buf(refdata[recnum].key, NULL);	/* custom allocation site */
    ivtmp = OPENSSL_hexstr2buf(refdata[recnum].iv, NULL);
    sq = OPENSSL_hexstr2buf(refdata[recnum].seq, NULL);
    pt = OPENSSL_hexstr2buf(refdata[recnum].plaintext, &ptlen);

    if (*key == NULL || ivtmp == NULL || sq == NULL || pt == NULL)
        goto err;

    rec->data = rec->input = OPENSSL_malloc(ptlen + EVP_GCM_TLS_TAG_LEN);

    if (rec->data == NULL)
        goto err;

    rec->length = ptlen;
    memcpy(rec->data, pt, ptlen);
    OPENSSL_free(pt);
    memcpy(seq, sq, SEQ_NUM_SIZE);
    OPENSSL_free(sq);
    memcpy(iv, ivtmp, ivlen);
    OPENSSL_free(ivtmp);

    return 1;
 err:
    OPENSSL_free(*key);
    OPENSSL_free(ivtmp);
    OPENSSL_free(sq);
    OPENSSL_free(pt);
    return 0;
}

static int test_tls13_encryption(void)
{
    SSL_CTX *ctx = NULL;
    SSL *s = NULL;
    SSL3_RECORD rec;
    unsigned char *key = NULL, *iv = NULL, *seq = NULL;
    const EVP_CIPHER *ciph = EVP_aes_128_gcm();
    int ret = 0;
    size_t ivlen, ctr;

    rec.data = NULL;

    ctx = SSL_CTX_new(TLS_method());
    if (ctx == NULL) {
        fprintf(stderr, "Failed creating SSL_CTX\n");
        goto err;
    }

    s = SSL_new(ctx);
    if (s == NULL) {
        fprintf(stderr, "Failed creating SSL\n");
        goto err;
    }

    for (ctr = 0; ctr < OSSL_NELEM(refdata); ctr++) {
        /*
         * Load the record, set up the read/write sequences and load the key into
         * the EVP_CIPHER_CTXs
         */
        ivlen = EVP_CIPHER_iv_length(ciph);
        if (!load_record(&rec, ctr, &key, s->read_iv, ivlen,
                         RECORD_LAYER_get_read_sequence(&s->rlayer))) {
            fprintf(stderr, "Failed loading key into EVP_CIPHER_CTX\n");
            goto err;
         }

        memcpy(RECORD_LAYER_get_write_sequence(&s->rlayer),
               RECORD_LAYER_get_read_sequence(&s->rlayer), SEQ_NUM_SIZE);
        memcpy(s->write_iv, s->read_iv, ivlen);

        if (EVP_CipherInit_ex(s->enc_write_ctx, ciph, NULL, key, NULL, 1) <= 0
                || EVP_CipherInit_ex(s->enc_read_ctx, ciph, NULL, key, NULL, 0)
                   <= 0) {
            fprintf(stderr, "Failed loading key into EVP_CIPHER_CTX\n");
            goto err;
        }

        /* Encrypt it */
        if (tls13_enc(s, &rec, 1, 1) != 1) {
            fprintf(stderr, "Failed to encrypt record\n");
            goto err;
        }

        if (!test_record(&rec, ctr, 1)) {
            fprintf(stderr, "Record encryption test failed\n");
            goto err;
        }

        /* Decrypt it */
        if (tls13_enc(s, &rec, 1, 0) != 1) {
            fprintf(stderr, "Failed to decrypt record\n");
            goto err;
        }

        if (!test_record(&rec, ctr, 0)) {
            fprintf(stderr, "Record decryption test failed\n");
            goto err;
        }

        OPENSSL_free(rec.data);
        OPENSSL_free(key);
        OPENSSL_free(iv);
        OPENSSL_free(seq);
        rec.data = NULL;
        key = NULL;
        iv = NULL;
        seq = NULL;
    }

    ret = 1;
 err:
    OPENSSL_free(rec.data);
    OPENSSL_free(key);
    OPENSSL_free(iv);
    OPENSSL_free(seq);
    SSL_free(s);
    SSL_CTX_free(ctx);

    return ret;
}

int main()
{
	test_tls13_encryption();
	return 0;
}


