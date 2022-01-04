#include <string>
#include <vector>

std::string cart_predict(std::vector<double> features) {
	if (features[2] <= 291.695) {
		if (features[345] <= 36.5456) {
			return ( "classical");
		} else {
			if (features[3] <= 403.59749999999997) {
				return ( "blues");
			} else {
				if (features[0] <= 39.730000000000004) {
					return ( "country");
				} else {
					return ( "jazz");
				}
			}
		}
	} else {
		if (features[486] <= 1.785635) {
			if (features[274] <= 185.993) {
				if (features[4] <= 234.765) {
					if (features[0] <= 77.87355) {
						return ( "jazz");
					} else {
						return ( "classical");
					}
				} else {
					if (features[50] <= 119.845) {
						return ( "blues");
					} else {
						if (features[0] <= 219.902) {
							return ( "metal");
						} else {
							return ( "hiphop");
						}
					}
				}
			} else {
				if (features[364] <= 62.2481) {
					if (features[261] <= 786.2065) {
						if (features[2] <= 520.8405) {
							if (features[6] <= 368.619) {
								if (features[0] <= 93.24465000000001) {
									return ( "country");
								} else {
									return ( "metal");
								}
							} else {
								return ( "blues");
							}
						} else {
							if (features[17] <= 482.875) {
								if (features[12] <= 150.421) {
									if (features[0] <= 208.868) {
										return ( "metal");
									} else {
										return ( "blues");
									}
								} else {
									if (features[3] <= 1647.365) {
										return ( "country");
									} else {
										return ( "blues");
									}
								}
							} else {
								return ( "blues");
							}
						}
					} else {
						return ( "blues");
					}
				} else {
					if (features[2] <= 1984.645) {
						return ( "blues");
					} else {
						return ( "hiphop");
					}
				}
			}
		} else {
			if (features[24] <= 194.7415) {
				if (features[259] <= 1110.585) {
					if (features[17] <= 281.85900000000004) {
						if (features[389] <= 34.8172) {
							if (features[0] <= 180.88635000000002) {
								return ( "classical");
							} else {
								return ( "jazz");
							}
						} else {
							if (features[1] <= 1024.1309999999999) {
								return ( "country");
							} else {
								return ( "hiphop");
							}
						}
					} else {
						return ( "disco");
					}
				} else {
					return ( "hiphop");
				}
			} else {
				if (features[43] <= 877.8520000000001) {
					if (features[11] <= 397.3435) {
						if (features[208] <= 16.54305) {
							if (features[0] <= 307.053) {
								return ( "metal");
							} else {
								return ( "hiphop");
							}
						} else {
							return ( "disco");
						}
					} else {
						if (features[495] <= 438.927) {
							if (features[256] <= 712.3755) {
								if (features[19] <= 865.8765000000001) {
									if (features[54] <= 117.602) {
										return ( "jazz");
									} else {
										if (features[25] <= 226.6695) {
											if (features[0] <= 175.7775) {
												return ( "classical");
											} else {
												return ( "country");
											}
										} else {
											if (features[448] <= 54.1068) {
												if (features[7] <= 736.5595000000001) {
													return ( "classical");
												} else {
													return ( "blues");
												}
											} else {
												if (features[0] <= 787.3164999999999) {
													return ( "disco");
												} else {
													return ( "country");
												}
											}
										}
									}
								} else {
									return ( "jazz");
								}
							} else {
								if (features[3] <= 1537.1750000000002) {
									return ( "hiphop");
								} else {
									return ( "rock");
								}
							}
						} else {
							if (features[381] <= 438.0915) {
								return ( "reggae");
							} else {
								if (features[288] <= 452.6035) {
									if (features[209] <= 859.1295) {
										if (features[69] <= 878.7985) {
											if (features[342] <= 452.534) {
												if (features[439] <= 456.098) {
													return ( "pop");
												} else {
													return ( "jazz");
												}
											} else {
												return ( "pop");
											}
										} else {
											return ( "disco");
										}
									} else {
										if (features[446] <= 443.62149999999997) {
											if (features[13] <= 878.1645) {
												return ( "pop");
											} else {
												return ( "metal");
											}
										} else {
											if (features[274] <= 451.2205) {
												if (features[432] <= 454.83500000000004) {
													return ( "metal");
												} else {
													return ( "metal");
												}
											} else {
												if (features[304] <= 444.091) {
													return ( "rock");
												} else {
													return ( "pop");
												}
											}
										}
									}
								} else {
									if (features[329] <= 450.9135) {
										if (features[193] <= 859.7445) {
											if (features[32] <= 879.752) {
												return ( "rock");
											} else {
												if (features[0] <= 765.924) {
													return ( "metal");
												} else {
													return ( "disco");
												}
											}
										} else {
											if (features[193] <= 869.3544999999999) {
												if (features[303] <= 456.8405) {
													return ( "disco");
												} else {
													return ( "pop");
												}
											} else {
												if (features[5] <= 865.1945000000001) {
													return ( "rock");
												} else {
													return ( "country");
												}
											}
										}
									} else {
										if (features[448] <= 459.9715) {
											if (features[442] <= 462.04449999999997) {
												if (features[415] <= 453.8365) {
													return ( "pop");
												} else {
													return ( "metal");
												}
											} else {
												return ( "reggae");
											}
										} else {
											if (features[419] <= 447.8985) {
												if (features[0] <= 783.4960000000001) {
													return ( "pop");
												} else {
													return ( "hiphop");
												}
											} else {
												return ( "disco");
											}
										}
									}
								}
							}
						}
					}
				} else {
					if (features[481] <= 443.3655) {
						if (features[138] <= 857.7185) {
							if (features[61] <= 947.3315) {
								return ( "jazz");
							} else {
								return ( "country");
							}
						} else {
							if (features[0] <= 832.7455) {
								return ( "rock");
							} else {
								return ( "reggae");
							}
						}
					} else {
						if (features[186] <= 870.5425) {
							if (features[507] <= 451.95799999999997) {
								if (features[424] <= 450.658) {
									if (features[470] <= 440.2965) {
										if (features[0] <= 865.4555) {
											return ( "hiphop");
										} else {
											return ( "country");
										}
									} else {
										return ( "reggae");
									}
								} else {
									if (features[505] <= 449.54949999999997) {
										if (features[3] <= 882.222) {
											if (features[1] <= 868.2284999999999) {
												return ( "disco");
											} else {
												return ( "jazz");
											}
										} else {
											return ( "reggae");
										}
									} else {
										return ( "rock");
									}
								}
							} else {
								if (features[135] <= 863.5464999999999) {
									if (features[473] <= 459.679) {
										if (features[14] <= 866.1595) {
											return ( "rock");
										} else {
											return ( "jazz");
										}
									} else {
										if (features[0] <= 809.102) {
											return ( "hiphop");
										} else {
											return ( "rock");
										}
									}
								} else {
									if (features[94] <= 865.989) {
										return ( "reggae");
									} else {
										if (features[0] <= 798.739) {
											return ( "pop");
										} else {
											return ( "jazz");
										}
									}
								}
							}
						} else {
							if (features[247] <= 863.4375) {
								if (features[1] <= 865.713) {
									return ( "hiphop");
								} else {
									return ( "disco");
								}
							} else {
								if (features[15] <= 858.185) {
									return ( "metal");
								} else {
									if (features[14] <= 859.5754999999999) {
										return ( "rock");
									} else {
										if (features[0] <= 768.723) {
											return ( "jazz");
										} else {
											if (features[0] <= 783.5545) {
												return ( "reggae");
											} else {
												if (features[0] <= 794.288) {
													return ( "country");
												} else {
													return ( "pop");
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}